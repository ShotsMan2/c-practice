#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int arr[])
{
    unsigned long long data = 0;
    int base[8], j = 8, i;

    for (i = 0; i < 8; i++)
    {
        data = data | ((unsigned long long)arr[i] << (i * 8));
    }

    printf("%llu\n", data);

    for (i = 0; i < 8; i++)
    {
        base[i] = (data >> i * 8) & 0xFF;

        printf("%d\n", base[i]);
    }
}

int main()
{
    int dizi[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    cevir(dizi);

    return 0;
}
