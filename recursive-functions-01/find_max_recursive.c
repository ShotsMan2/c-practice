#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int enbuyukbul(int arr[], int size)
{
    if (size == 1)
    {
        return arr[0];
    }

    int kalanenbuyuk = enbuyukbul(arr, size - 1);

    if (kalanenbuyuk < arr[size - 1])
    {
        return arr[size - 1];
    }
    else
    {
        return kalanenbuyuk;
    }
}

int main()
{
    int sayilar[10] = {12, 45, 7, 89, 23, 56, 91, 34, 67, 5};

    int boyut = 10;

    int result = enbuyukbul(sayilar, boyut);

    printf("%d", result);

    return 0;
}
