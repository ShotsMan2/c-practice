#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printarray(char **sehirler)
{
    int i = 0;

    while (*(sehirler + i) != NULL)
    {
        printf("%s\n", *(sehirler + i));
        i++;
    }
}

void ekle(int index, char *yeniSehir, char **sehirler)
{
    int son = 0, uzunluk = 0, i;

    while (*(sehirler + son) != NULL)
    {
        son++;
    }

    for (i = son; i > index; i--)
    {
        *(sehirler + i) = *(sehirler + i - 1);
    }

    while (*(yeniSehir + uzunluk) != '\0')
    {
        uzunluk++;
    }

    char *kalicisehir = (char *)malloc((uzunluk + 1) * sizeof(char));

    for (i = 0; i < uzunluk; i++)
    {
        *(kalicisehir + i) = *(yeniSehir + i);
    }
    *(kalicisehir + uzunluk) = '\0';

    *(sehirler + index) = kalicisehir;

    printarray(sehirler);
}

void sonaekle(char *yeniSehir, char **sehirler)
{
    int son = 0, len = 0, i;

    while (*(sehirler + son) != NULL)
    {
        son++;
    }

    while (*(yeniSehir + len) != '\0')
    {
        len++;
    }

    char *kalicisehir = (char *)malloc((len + 1) * sizeof(char));

    for (i = 0; i < len; i++)
    {
        *(kalicisehir + i) = *(yeniSehir + i);
    }

    *(kalicisehir + len) = '\0';

    *(sehirler + son) = kalicisehir;

    printarray(sehirler);
}

void sil(int index, char **sehirler)
{
    int son = 0, i;

    while (*(sehirler + son) != NULL)
    {
        son++;
    }

    for (i = index; i < son; i++)
    {
        *(sehirler + i) = *(sehirler + i + 1);
    }

    printarray(sehirler);
}

void silkelime()
{
}

void duzenle(char *onceki, char *sonraki, char **sehirler)
{
    int oncekilen = 0, sonrakilen = 0;

    while (*(onceki + oncekilen) != '\0')
    {
        oncekilen++;
    }
    while (*(sonraki + sonrakilen) != '\0')
    {
        sonrakilen++;
    }
}

void duzenlecizgi()
{
}

void bul()
{
}

void terscevir()
{
}

void yerdegistir()
{
}

int main()
{
    char sehir[50], *sehirler[50] = {"Ankara", "Istanbul", "Izmir", "Konya", "Antalya", "Trabzon", "Samsun", "Manisa", "Mus"};
    char harf, once[50], sonra[50];
    int index;

    printf("harf gir ");
    scanf(" %c", &harf);

    if (harf == 'a')
    {
        printf("index gir ");
        scanf("%d", &index);
        printf("sehir gir ");
        scanf("%s", sehir);
        ekle(index, sehir, sehirler);
    }
    else if (harf == 'b')
    {
        printf("sehir gir ");
        scanf("%s", sehir);
        sonaekle(sehir, sehirler);
    }
    else if (harf == 'c')
    {
        printf("silinecek indexi gir ");
        scanf("%d", &index);
        sil(index, sehirler);
    }
    else if (harf == 'd')
    {
        silkelime();
    }
    else if (harf == 'e')
    {
        printf("oncekini gir ");
        scanf("%s", once);
        printf("sonrakini gir ");
        scanf("%s", sonra);

        duzenle(once, sonra, sehirler);
    }
    else if (harf == 'f')
    {
        duzenlecizgi();
    }
    else if (harf == 'g')
    {
        bul();
    }
    else if (harf == 'h')
    {
        terscevir();
    }
    else if (harf == 'i')
    {
        yerdegistir();
    }

    return 0;
}
