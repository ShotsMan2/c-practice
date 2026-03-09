#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matris[10][5], i, j;
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

    fptr = fopen("tek.txt", "w");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (i = 0; i < 10; i = i + 2)
        {
            for (j = 0; j < 5; j++)
            {
                fprintf(fptr, "%d\t", matris[i][j]);
            }
            fprintf(fptr, "\n");
        }

        printf("scs");
        fclose(fptr);
    }
    fptr = fopen("cift.txt", "w");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (i = 1; i < 10; i = i + 2)
        {
            for (j = 0; j < 5; j++)
            {
                fprintf(fptr, "%d\t", matris[i][j]);
            }
            fprintf(fptr, "\n");
        }

        printf("scs");
        fclose(fptr);
    }

    return 0;
}
