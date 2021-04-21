#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    int a = 1, num = 0;
    uint8_t temp[512];
    char *file = (char *) calloc(8, sizeof(char));
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./recover [key]");
        return 1;
    }
    FILE *raw = fopen(argv[1], "r");
    if (raw == NULL)
    {
        printf("Unable to open the file.");
        return 1;
    }
    while (true)
    {
        while (a == 1)
        {
            fread(temp, 512, 1, raw);
            if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
            {
                a = 2;
            }
        }
        if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
        {
            sprintf(file, "%03i.jpg", num);
            FILE *image = fopen(file, "w");
            fwrite(temp, 512, 1, image);
            while (true)
            {
                int b = fread(temp, 512, 1, raw);
                if (b < 1)
                {
                    fclose(image);
                    a = 5;
                    break;
                }
                if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
                {
                    num++;
                    fclose(image);
                    break;
                }
                fwrite(temp, 512, 1, image);
            }
        }
        if (a == 5)
        {
            break;
        }
    }
    fclose(raw);
    free(file);
    return 0;
}