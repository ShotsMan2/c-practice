#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int enkucukbul(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int kalanenkucuk = enkucukbul(arr, size - 1);

    if (kalanenkucuk > arr[size - 1])
    {
        return arr[size - 1];
    }
    else
    {
        return kalanenkucuk;
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

int maxminfark(int arr[], int size)
{
    int max = enbuyukbul(arr, size);
    int min = enkucukbul(arr, size);

    return max - min;
}

int main()
{
    int sayilar[10] = {12, 45, 7, 89, 23, 56, 92, 34, 67, 5};

    int boyut = 10;

    int result = maxminfark(sayilar, boyut);

    printf("%d", result);

    return 0;
}
