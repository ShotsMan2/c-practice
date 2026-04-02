#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int matris[10][10];
    int kat7 = 7, i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            *(*(matris + i) + j) = kat7;
            kat7 += 7;
        }
    }

    for (i = 9; i >= 0; i--)
    {
        for (j = 9; j >= 0; j--)
        {
            printf("%d\t", *(*(matris + i) + j));
        }
        printf("\n");
    }

    return 0;
}
