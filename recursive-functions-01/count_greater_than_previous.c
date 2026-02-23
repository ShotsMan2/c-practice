#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buyukmu(int arr[], int size)
{
    if (size <= 1)
    {
        return 0;
    }

    if (arr[size - 2] < arr[size - 1])
    {
        return 1 + buyukmu(arr, size - 1);
    }
    else
    {
        return buyukmu(arr, size - 1);
    }
}

int main()
{
    int arr[8] = {1, 5, 7, 19, 14, 4, 8, 5};

    int size = 8;

    int result = buyukmu(arr, size);

    printf("%d", result);

    return 0;
}
