#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void rastgeleoku(FILE *fptr, int baslangicindex, int artismik)
{

    int i = 0, j;
    char arr[50];
    while ((arr[i] = getc(fptr)) != EOF)
    {
        i++;
    }

    for (j = baslangicindex; j < i; j = j + artismik)
    {
        printf("%c", arr[j]);
    }
}

int main()
{
    int index, artis;
    FILE *fptr;
    fptr = fopen("dosya.txt", "r");

    printf("baslangic indexi gir ");
    scanf("%d", &index);

    printf("artis miktarini gir");
    scanf("%d", &artis);

    rastgeleoku(fptr, index, artis);

    fclose(fptr);

    return 0;
}
