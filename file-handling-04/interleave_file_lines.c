#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    char cop[7][50];
    int i = 0, bas, son;

    FILE *fptr, *fyaz;
    fptr = fopen("string.dat", "r");
    fyaz = fopen("string2.dat", "w");
    if (fptr == NULL || fyaz == NULL)
    {
        printf("unsc");
    }
    else
    {
        while (i < 6 && fgets(cop[i], sizeof(cop[i]), fptr) != NULL)
        {
            i++;
        }

        bas = 0;
        son = i - 1;

        while (bas <= son)
        {
            if (bas == son)
            {
                fprintf(fyaz, "%s", cop[bas]);
            }
            else
            {
                fprintf(fyaz, "%s", cop[bas]);
                fprintf(fyaz, "%s", cop[son]);
            }

            bas++;
            son--;
        }

        printf("scs");
        fclose(fptr);
        fclose(fyaz);
    }

    return 0;
}
