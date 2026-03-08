#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int sum, arr[4], i, j;
    float ort;
    FILE *fprt;
    fprt = fopen("ikiliDosya.dat", "rb");

    if (fprt == NULL)
    {
        printf("unsc");
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            fread(arr, sizeof(int), 4, fprt);

            sum = 0;
            for (j = 0; j < 4; j++)
            {
                sum += arr[j];
            }

            ort = sum / 4.0;

            printf("%d. gruo ortu: %.2f\n", i + 1, ort);
        }

        printf("scs");
    }

    fclose(fprt);

    return 0;
}
