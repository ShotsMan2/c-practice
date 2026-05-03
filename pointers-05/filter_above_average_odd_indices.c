#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, avg, sum = 0, count = 0, numbers[] = {20, 60, 45, 42, 23, 24, 26, 125, 66, 55, 145, 50, 30, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (i = 1; i < size; i = i + 2)
    {
        sum += *(numbers + i);
        count++;
    }

    avg = sum / count;

    for (i = 1; i < size; i = i + 2)
    {
        if (avg < *(numbers + i))
        {
            printf("%d\n", *(numbers + i));
        }
    }

    return 0;
}
