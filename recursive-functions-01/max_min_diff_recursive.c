#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int minOfRest = findMin(arr, size - 1);

    if (minOfRest > arr[size - 1])
    {
        return arr[size - 1];
    }
    else
    {
        return minOfRest;
    }
}

int findMax(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int maxOfRest = findMax(arr, size - 1);

    if (maxOfRest > arr[size - 1])
    {
        return maxOfRest;
    }
    else
    {
        return arr[size - 1];
    }
}

int maxMinDiff(int arr[], int size)
{
    int max = findMax(arr, size);
    int min = findMin(arr, size);

    return max - min;
}

int main()
{
    int numbers[10] = {12, 45, 7, 89, 23, 56, 92, 34, 67, 5};

    int size = 10;

    int result = maxMinDiff(numbers, size);

    printf("%d", result);

    return 0;
}
