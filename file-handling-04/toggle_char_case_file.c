#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int harf;

    FILE *foku, *fyaz;
    foku = fopen("dosya.txt", "r");
    fyaz = fopen("dosya2.txt", "w");
    if (foku == NULL || fyaz == NULL)
    {
        printf("unsc");
    }
    else
    {
        while ((harf = fgetc(foku)) != EOF)
        {
            if (harf >= 65 && harf <= 90)
            {
                harf = harf + 32;
            }
            else if (harf >= 97 && harf <= 122)
            {
                harf = harf - 32;
            }

            fputc(harf, fyaz);
        }

        printf("scs");
        fclose(foku);
        fclose(fyaz);
    }

    return 0;
}
