#include <stdio.h>
#include <stdlib.h>

int findsecondmax(int arr[], int size, int *max, int *secondmax)
{
    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            *max = arr[0];
            *secondmax = arr[1];
        }
        else
        {
            *max = arr[1];
            *secondmax = arr[0];
        }
        return 0;
    }

    findsecondmax(arr, size - 1, max, secondmax);

    int lastelement = arr[size - 1];

    if (lastelement > *max)
    {
        *secondmax = *max;
        *max = lastelement;
    }
    else if (lastelement > *secondmax && lastelement != *max)
    {
        *secondmax = lastelement;
    }
}

int main()
{
    int numbers[10] = {12, 45, 7, 89, 23, 56, 91, 34, 67, 5};
    int size = 10;

    // Şampiyon ve ikinciyi tutacağımız boş değişkenler
    int maxDeger, ikinciDeger;

    findsecondmax(numbers, size, &maxDeger, &ikinciDeger);

    // Sonuçları ekrana yazdırıyoruz
    printf("En buyuk sayi (Sampiyon): %d\n", maxDeger);
    printf("En buyuk 2. sayi (Ikinci): %d\n", ikinciDeger);

    return 0;
}
