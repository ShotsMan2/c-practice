#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num, max = 0, min = 0, matris[10][5], j;
    float avg, sum = 0;

    FILE *fptr;
    fptr = fopen("randomnumber.txt", "r");
    if (fptr == NULL)
    {
        printf("unsc");
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

        printf("scs");
        fclose(fptr);
    }

    fptr = fopen("randomnumber.txt", "w");

    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            min = matris[i][0];
            max = matris[i][0];
            avg = 0;
            sum = 0.0;

            for (j = 0; j < 5; j++)
            {
                fprintf(fptr, "%d ", matris[i][j]);

                if (min > matris[i][j])
                {
                    min = matris[i][j];
                }
                if (max < matris[i][j])
                {
                    max = matris[i][j];
                }
                sum += matris[i][j];
            }

            avg = sum / 5.0;

            fprintf(fptr, "min: %d max: %d avg: %.1f\n", min, max, avg);
        }

        printf("scs");
        fclose(fptr);
    }

    return 0;
}
