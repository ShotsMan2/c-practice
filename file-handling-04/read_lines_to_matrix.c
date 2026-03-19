#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    char matris[5][50];
    int i;

    FILE *fptr;
    fptr = fopen("string.dat", "r");
    if (fptr == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            fgets(matris[i], sizeof(matris[i]), fptr);
        }

        for (i = 4; i >= 0; i--)
        {
            printf("%s", matris[i]);
        }

        printf("scs");
        fclose(fptr);
    }

    return 0;
}
