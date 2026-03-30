#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int arr[10], i, count = 0;

    for (i = 99; i >= -100; i--)
    {
        if (i % 2 == 0 && i % 3 != 0)
        {
            *(arr + count) = i;
            count++;
        }
        if (count >= 10)
        {
            break;
        }
    }

    for (i = 9; i >= 0; i--)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}
