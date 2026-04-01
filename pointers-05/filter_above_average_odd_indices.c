#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, ort, sum = 0, count = 0, sayilar[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(sayilar) / sizeof(sayilar[0]);

    for (i = 1; i < size; i = i + 2)
    {
        sum += *(sayilar + i);
        count++;
    }

    ort = sum / count;

    for (i = 1; i < size; i = i + 2)
    {
        if (ort < *(sayilar + i))
        {
            printf("%d\n", *(sayilar + i));
        }
    }

    return 0;
}
