#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, sayilar[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(sayilar) / sizeof(sayilar[0]);

    for (i = 0; i < size; i++)
    {
        if (*(sayilar + i) % 2 == 0)
        {
            (*(sayilar + i))++;
        }
    }

    for (i = 0; i < size; i++)
    {
        printf("%d\n", *(sayilar + i));
    }

    return 0;
}
