#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMax(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int maxOfRest = findMax(arr, size - 1);

    if (maxOfRest < arr[size - 1])
    {
        return arr[size - 1];
    }
    else
    {
        return maxOfRest;
    }
}

int main()
{
    int numbers[10] = {12, 45, 7, 89, 23, 56, 91, 34, 67, 5};

    int size = 10;

    int result = findMax(numbers, size);

    printf("%d", result);

    return 0;
}
