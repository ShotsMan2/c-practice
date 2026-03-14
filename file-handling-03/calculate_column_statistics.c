#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matris[10][5], i, j, max[5], min[5], avg[5], sum[5];

    FILE *fptr;
    fptr = fopen("randomnumber.txt", "r");
    if (fptr == NULL)
    {
        printf("unsuccessful");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 5; j++)
            {
                fscanf(fptr, "%d ", &matris[i][j]);
            }
        }

        printf("successful");
    }

    if (fptr == NULL)
    {
        printf("unsuccessful");
    }
    else
    {
        for (j = 0; j < 5; j++)
        {
            max[j] = matris[0][j];
            min[j] = matris[0][j];
            sum[j] = 0;

            for (i = 0; i < 10; i++)
            {
                if (max[j] < matris[i][j])
                {
                    max[j] = matris[i][j];
                }
                if (min[j] > matris[i][j])
                {
                    min[j] = matris[i][j];
                }
                sum[j] += matris[i][j];
            }
            avg[j] = sum[j] / 10;
        }

        printf("successful");
        fclose(fptr);
    }

    fptr = fopen("randomnumber.txt", "w");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            fprintf(fptr, "%d\t", matris[i][j]);
        }
        fprintf(fptr, "\n");
    }

    for (i = 0; i < 5; i++)
    {
        fprintf(fptr, "max:%d\t", max[i]);
    }
    fprintf(fptr, "\n");
    for (i = 0; i < 5; i++)
    {
        fprintf(fptr, "min:%d\t", min[i]);
    }
    fprintf(fptr, "\n");
    for (i = 0; i < 5; i++)
    {
        fprintf(fptr, "avg:%d\t", avg[i]);
    }
    fprintf(fptr, "\n");

    return 0;
}
