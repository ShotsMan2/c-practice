#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int len[6], i = 0, j, k;
    char data[6][50];

    FILE *fptr;
    fptr = fopen("string.dat", "r");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        while (i < 6 && fgets(data[i], sizeof(data[i]), fptr) != NULL)
        {
            data[i][strcspn(data[i], "\n")] = '\0';

            j = 0;
            while (data[i][j] != '\0')
            {
                j++;
            }
            len[i] = j;
            i++;
        }

        printf("scs");
        fclose(fptr);
    }
    fptr = fopen("string.dat", "w");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (k = 0; k < i; k++)
        {
            fprintf(fptr, "%d %s\n", len[k], data[k]);
        }

        printf("scs");
        fclose(fptr);
    }

    return 0;
}
