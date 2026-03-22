#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    char opsiyon[10], depo[6][50];
    int i = 0;

    FILE *fptr, *fyaz;
    fptr = fopen("string.dat", "r");
    fyaz = fopen("tekcift.txt", "w");
    if (fptr == NULL || fyaz == NULL)
    {
        printf("unsc");
    }
    else
    {
        printf("tek mi cift mi ");
        scanf("%s", opsiyon);
        if (strcmp(opsiyon, "tek") == 0)
        {
            while (fgets(depo[i], sizeof(depo[i]), fptr) != NULL)
            {
                if (i % 2 == 0)
                {
                    fprintf(fyaz, "%s", depo[i]);
                }
                i++;
            }
            printf("scs");
        }
        else if (strcmp(opsiyon, "cift") == 0)
        {
            while (fgets(depo[i], sizeof(depo[i]), fptr) != NULL)
            {
                if (i % 2 == 1)
                {
                    fprintf(fyaz, "%s", depo[i]);
                }
                i++;
            }
            printf("scs");
        }

        fclose(fptr);
        fclose(fyaz);
    }

    return 0;
}
