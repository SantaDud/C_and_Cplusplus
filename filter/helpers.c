#include<math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    float average;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Calculate average of channel values.
            average = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3);
            //Assign the average to each individual channel.
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    RGBTRIPLE temp;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < round(width / 2); j++)
        {
            //Switch the places of the appropriate pixels.
            temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j;
    float a, redtemp[height][width], bluetemp[height][width], greentemp[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Initialize the temporary variables.
            redtemp[i][j] = 0;
            bluetemp[i][j] = 0;
            greentemp[i][j] = 0;
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            a = 1;
            bluetemp[i][j] += image[i][j].rgbtBlue;
            greentemp[i][j] += image[i][j].rgbtGreen;
            redtemp[i][j] += image[i][j].rgbtRed;
            //Adding the appropriate pixel channel values to 
            //temporary variable from the image pixels.
            if ((i - 1) >= 0 && (j - 1) >= 0)
            {
                bluetemp[i][j] += image[i - 1][j - 1].rgbtBlue;
                greentemp[i][j] += image[i - 1][j - 1].rgbtGreen;
                redtemp[i][j] += image[i - 1][j - 1].rgbtRed;
                a++;
            }
            if ((i - 1) >= 0)
            {
                bluetemp[i][j] += image[i - 1][j].rgbtBlue;
                greentemp[i][j] += image[i - 1][j].rgbtGreen;
                redtemp[i][j] += image[i - 1][j].rgbtRed;
                a++;
            }
            if ((i - 1) >= 0 && (j + 1) < width)
            {
                bluetemp[i][j] += image[i - 1][j + 1].rgbtBlue;
                greentemp[i][j] += image[i - 1][j + 1].rgbtGreen;
                redtemp[i][j] += image[i - 1][j + 1].rgbtRed;
                a++;
            }
            if ((j - 1) >= 0)
            {
                bluetemp[i][j] += image[i][j - 1].rgbtBlue;
                greentemp[i][j] += image[i][j - 1].rgbtGreen;
                redtemp[i][j] += image[i][j - 1].rgbtRed;
                a++;
            }
            if ((j + 1) < width)
            {
                bluetemp[i][j] += image[i][j + 1].rgbtBlue;
                greentemp[i][j] += image[i][j + 1].rgbtGreen;
                redtemp[i][j] += image[i][j + 1].rgbtRed;
                a++;
            }
            if ((i + 1) < height && (j - 1) >= 0)
            {
                bluetemp[i][j] += image[i + 1][j - 1].rgbtBlue;
                greentemp[i][j] += image[i + 1][j - 1].rgbtGreen;
                redtemp[i][j] += image[i + 1][j - 1].rgbtRed;
                a++;
            }
            if ((i + 1) < height)
            {
                bluetemp[i][j] += image[i + 1][j].rgbtBlue;
                greentemp[i][j] += image[i + 1][j].rgbtGreen;
                redtemp[i][j] += image[i + 1][j].rgbtRed;
                a++;
            }
            if ((i + 1) < height && (j + 1) < width)
            {
                bluetemp[i][j] += image[i + 1][j + 1].rgbtBlue;
                greentemp[i][j] += image[i + 1][j + 1].rgbtGreen;
                redtemp[i][j] += image[i + 1][j + 1].rgbtRed;
                a++;
            }
            //Find the average of temporary variable
            bluetemp[i][j] = round(bluetemp[i][j] / a);
            greentemp[i][j] = round(greentemp[i][j] / a);
            redtemp[i][j] = round(redtemp[i][j] / a);

        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Assign the value to the pixels of image from the temporary variable.
            image[i][j].rgbtBlue = bluetemp[i][j];
            image[i][j].rgbtRed = redtemp[i][j];
            image[i][j].rgbtGreen = greentemp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, temp1, temp2, temp3;
    float redtempx[height][width], bluetempx[height][width], greentempx[height][width], redtempy[height][width],
          bluetempy[height][width], greentempy[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Initialize the temporary variables of x and y.
            redtempx[i][j] = 0;
            bluetempx[i][j] = 0;
            greentempx[i][j] = 0;
            redtempy[i][j] = 0;
            bluetempy[i][j] = 0;
            greentempy[i][j] = 0;
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Add the appropriate values to the temporary variables of x and y.
            //The values are mutiplied by the appropriate values
            //from the convolution matrix before being added.
            if ((i - 1) >= 0 && (j - 1) >= 0)
            {
                bluetempx[i][j] += (image[i - 1][j - 1].rgbtBlue * -1);
                greentempx[i][j] += (image[i - 1][j - 1].rgbtGreen * -1);
                redtempx[i][j] += (image[i - 1][j - 1].rgbtRed * -1);
                bluetempy[i][j] += (image[i - 1][j - 1].rgbtBlue * -1);
                greentempy[i][j] += (image[i - 1][j - 1].rgbtGreen * -1);
                redtempy[i][j] += (image[i - 1][j - 1].rgbtRed * -1);
            }
            if ((i - 1) >= 0)
            {
                bluetempx[i][j] += (image[i - 1][j].rgbtBlue * 0);
                greentempx[i][j] += (image[i - 1][j].rgbtGreen * 0);
                redtempx[i][j] += (image[i - 1][j].rgbtRed * 0);
                bluetempy[i][j] += (image[i - 1][j].rgbtBlue * -2);
                greentempy[i][j] += (image[i - 1][j].rgbtGreen * -2);
                redtempy[i][j] += (image[i - 1][j].rgbtRed * -2);
            }
            if ((i - 1) >= 0 && (j + 1) < width)
            {
                bluetempx[i][j] += (image[i - 1][j + 1].rgbtBlue * 1);
                greentempx[i][j] += (image[i - 1][j + 1].rgbtGreen * 1);
                redtempx[i][j] += (image[i - 1][j + 1].rgbtRed * 1);
                bluetempy[i][j] += (image[i - 1][j + 1].rgbtBlue * -1);
                greentempy[i][j] += (image[i - 1][j + 1].rgbtGreen * -1);
                redtempy[i][j] += (image[i - 1][j + 1].rgbtRed * -1);
            }
            if ((j - 1) >= 0)
            {
                bluetempx[i][j] += (image[i][j - 1].rgbtBlue * -2);
                greentempx[i][j] += (image[i][j - 1].rgbtGreen * -2);
                redtempx[i][j] += (image[i][j - 1].rgbtRed * -2);
                bluetempy[i][j] += (image[i][j - 1].rgbtBlue * 0);
                greentempy[i][j] += (image[i][j - 1].rgbtGreen * 0);
                redtempy[i][j] += (image[i][j - 1].rgbtRed * 0);
            }
            if ((j + 1) < width)
            {
                bluetempx[i][j] += (image[i][j + 1].rgbtBlue * 2);
                greentempx[i][j] += (image[i][j + 1].rgbtGreen * 2);
                redtempx[i][j] += (image[i][j + 1].rgbtRed * 2);
                bluetempy[i][j] += (image[i][j + 1].rgbtBlue * 0);
                greentempy[i][j] += (image[i][j + 1].rgbtGreen * 0);
                redtempy[i][j] += (image[i][j + 1].rgbtRed * 0);
            }
            if ((i + 1) < height && (j - 1) >= 0)
            {
                bluetempx[i][j] += (image[i + 1][j - 1].rgbtBlue * -1);
                greentempx[i][j] += (image[i + 1][j - 1].rgbtGreen * -1);
                redtempx[i][j] += (image[i + 1][j - 1].rgbtRed * -1);
                bluetempy[i][j] += (image[i + 1][j - 1].rgbtBlue * 1);
                greentempy[i][j] += (image[i + 1][j - 1].rgbtGreen * 1);
                redtempy[i][j] += (image[i + 1][j - 1].rgbtRed * 1);
            }
            if ((i + 1) < height)
            {
                bluetempx[i][j] += (image[i + 1][j].rgbtBlue * 0);
                greentempx[i][j] += (image[i + 1][j].rgbtGreen * 0);
                redtempx[i][j] += (image[i + 1][j].rgbtRed * 0);
                bluetempy[i][j] += (image[i + 1][j].rgbtBlue * 2);
                greentempy[i][j] += (image[i + 1][j].rgbtGreen * 2);
                redtempy[i][j] += (image[i + 1][j].rgbtRed * 2);
            }
            if ((i + 1) < height && (j + 1) < width)
            {
                bluetempx[i][j] += (image[i + 1][j + 1].rgbtBlue * 1);
                greentempx[i][j] += (image[i + 1][j + 1].rgbtGreen * 1);
                redtempx[i][j] += (image[i + 1][j + 1].rgbtRed * 1);
                bluetempy[i][j] += (image[i + 1][j + 1].rgbtBlue * 1);
                greentempy[i][j] += (image[i + 1][j + 1].rgbtGreen * 1);
                redtempy[i][j] += (image[i + 1][j + 1].rgbtRed * 1);
            }
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //Combining the final values of the x and y temporary variable
            //and round them to the nearest integer.
            temp1 = round((sqrtf(pow(redtempx[i][j], 2) + pow(redtempy[i][j], 2))));
            temp2 = round((sqrtf(pow(bluetempx[i][j], 2) + pow(bluetempy[i][j], 2))));
            temp3 = round((sqrtf(pow(greentempx[i][j], 2) + pow(greentempy[i][j], 2))));
            //Checks to make sure that no value is above 255.
            //If they are then they are changed to 255.
            if (temp1 > 255)
            {
                temp1 = 255;
            }
            if (temp2 > 255)
            {
                temp2 = 255;
            }
            if (temp3 > 255)
            {
                temp3 = 255;
            }
            //Assigning the value to the image pixel.
            image[i][j].rgbtRed = temp1;
            image[i][j].rgbtBlue = temp2;
            image[i][j].rgbtGreen = temp3;
        }
    }
    return;
}