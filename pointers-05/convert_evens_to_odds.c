#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, numbers[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (i = 0; i < size; i++)
    {
        if (*(numbers + i) % 2 == 0)
        {
            (*(numbers + i))++;
        }
    }

    for (i = 0; i < size; i++)
    {
        printf("%d\n", *(numbers + i));
    }

    return 0;
}
