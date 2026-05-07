#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, count = 0, numbers[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (i = 0; i < size - 1; i++)
    {
        if (*(numbers + i) % 2 == 0 && *(numbers + i + 1) % 2 == 0)
        {
            count++;
            printf("%d-%d\n", *(numbers + i), *(numbers + i + 1));
        }
    }

    printf("%d", count);

    return 0;
}
