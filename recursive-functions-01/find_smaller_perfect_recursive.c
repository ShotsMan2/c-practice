#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bolentoplami(int sayi, int bolen)
{
    if (bolen == 0)
    {
        return 0;
    }

    if (sayi % bolen == 0)
    {
        return bolen + bolentoplami(sayi, bolen - 1);
    }
    else
    {
        return bolentoplami(sayi, bolen - 1);
    }
}
int mukemmelbul(int sayi)
{
    if (sayi < 6)
    {
        return -1;
    }

    int toplam = bolentoplami(sayi, sayi - 1);

    if (toplam == sayi)
    {
        return toplam;
    }

    return mukemmelbul(sayi - 1);
}

int main()
{
    int sayi;

    printf("sayi gir ");
    scanf("%d", &sayi);

    int result = mukemmelbul(sayi - 1);

    if (result == -1)
    {
        printf("muk sayi yok");
    }
    else
    {
        printf("muk sayi: %d", result);
    }

    return 0;
}
