#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, count = 0, sayilar[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(sayilar) / sizeof(sayilar[0]);

    for (i = 0; i < size - 1; i++)
    {
        if (*(sayilar + i) % 2 == 0 && *(sayilar + i + 1) % 2 == 0)
        {
            count++;
            printf("%d-%d\n", *(sayilar + i), *(sayilar + i + 1));
        }
    }

    printf("%d", count);

    return 0;
}
