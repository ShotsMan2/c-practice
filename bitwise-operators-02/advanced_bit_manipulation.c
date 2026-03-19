#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bityazdir(int sayi)
{
    int i;

    for (i = 4; i >= 0; i--)
    {
        int bit = (sayi >> i) & 1;

        printf("%d", bit);
    }
}
void bityazdir6(int sayi)
{
    int i;

    for (i = 5; i >= 0; i--)
    {
        int bit = (sayi >> i) & 1;

        printf("%d", bit);
    }
}

int main()
{
    int arr[7], i;

    srand(time(NULL));

    for (i = 0; i < 5; i++)
    {
        arr[i] = rand() % 32;
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d(", arr[i]);
        bityazdir(arr[i]);
        printf("), ");
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        if (((arr[i] >> 4) & 1) == 0)
        {
            arr[i] = (arr[i] << 2) & 31;
        }
        else
        {
            arr[i] = arr[i] >> 2;
        }
    }

    printf("adim 1: ");
    for (i = 0; i < 5; i++)
    {

        bityazdir(arr[i]);
        printf(", ");
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        arr[i] = arr[i] | 1;
    }

    printf("adim 2: ");
    for (i = 0; i < 5; i++)
    {

        bityazdir(arr[i]);
        printf(", ");
    }
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        int sagkisim = arr[i] & 7;
        int solkisim = (arr[i] >> 3) << 4;

        arr[i] = solkisim | sagkisim;
    }

    printf("adim 3-4: ");

    for (i = 0; i < 5; i++)
    {

        bityazdir6(arr[i]);
        printf("= %d", arr[i]);
        printf(", ");
    }

    printf("\n");

    return 0;
}
