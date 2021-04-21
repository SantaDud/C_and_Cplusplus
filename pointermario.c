/*#include<stdio.h>
int* sum(int*,int*);
int main(void)
{
    int a[2][2], b[2][2], *py, e, *px, *pq, c, d;
    for (c = 0; c < 2; c++)
    {
        for (d = 0; d < 2; d++)
        {
            printf("enter first:");
            scanf("%d", &a[c][d]);
            printf("enter second:");
            scanf("%d", &b[c][d]);
        }
    }
    px = &a[0][0];
    py = &b[0][0];
    for (e = 0; e < 4; e++)
    printf("\t\t%d\n", *(sum(px,py)+e));
    getch();
}
int* sum(int *px,int *py)
{
    int *pz, b, a[4];
        for (b = 0; b < 4; b++)
    {
        a[b] = *(px+b) + *(py+b);
    }

    pz = a;
    return(pz);
}*/



/*#include<stdio.h>
int main(void)
{
    int a,i,j,k,l;
    do
    {
        printf("Height: ");
        scanf("%d",&a);
    }
    while (a < 1 || a > 8);
    l = a - 1;
    for (i = 1; i <= a; i++)
    {
        for (k = 0; k < i; k++)
        {
            if (k == 0)
            {
                for (j = l; j > 0; j--)
                {
                    printf(" ");
                }
                l -= 1;
            }
            printf("#");
        }
        printf("  ");
        for (k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}*/


