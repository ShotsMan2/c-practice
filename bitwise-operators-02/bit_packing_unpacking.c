#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cevir(int sayi1, int sayi2)
{
    int data;

    data = sayi2 | sayi1 << 8;

    printf("%d\n", data);

    int cozulensayi2 = data & 255;

    int cozulensayi1 = (data >> 8) & 255;

    printf("sayi1= %d\n", cozulensayi1);
    printf("sayi2= %d\n", cozulensayi2);
}

int main()
{
    int sayi1 = 5, sayi2 = 7;

    cevir(sayi1, sayi2);

    return 0;
}
