#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    int arr[5], sum = 0, i;

    for (i = 10; i < 1000; i++)
    {
        if (i % 2 == 1 && i % 3 == 0)
        {
            *(arr + sum) = i;
            sum++;
        }
        if (sum >= 5)
        {
            break;
        }
    }

    for (i = 4; i >= 0; i--)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}
