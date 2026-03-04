#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int rustMin = findMin(arr, size - 1);

    if (rustMin > arr[size - 1])
    {
        return arr[size - 1];
    }
    else
    {
        return rustMin;
    }
}

int enbuyukbul(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int kalanenbuyuk = enbuyukbul(arr, size - 1);

    if (kalanenbuyuk > arr[size - 1])
    {
        return kalanenbuyuk;
    }
    else
    {
        return arr[size - 1];
    }
}

int maxMinDiff(int arr[], int size)
{
    int max = enbuyukbul(arr, size);
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
