#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int n, i, yon;
    char isim[20];

    srand(time(NULL));

    printf("n i girin ");
    scanf("%d", &n);

    getchar();

    FILE *fogrenci, *fadim;
    fogrenci = fopen("ogrenci.txt", "w");
    fadim = fopen("adimsayisi.txt", "w");
    if (fogrenci == NULL || fadim == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            fprintf(fadim, "%d\n", (rand() % 8) + 2);
        }

        for (i = 0; i < n; i++)
        {
            printf("%d. kaydi girin ", i + 1);
            gets(isim);
            fprintf(fogrenci, "%d. KAYIT: %s\n", i + 1, isim);
        }

        printf("scs\n");
        fclose(fogrenci);
        fclose(fadim);
    }

    int ogrenci[50], adim[50], yazdirildi[50] = {0};
    char satiroku[50];

    fogrenci = fopen("ogrenci.txt", "r");
    fadim = fopen("adimsayisi.txt", "r");
    if (fogrenci == NULL || fadim == NULL)
    {
        printf("unsc\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            ogrenci[i] = ftell(fogrenci);

            fgets(satiroku, sizeof(satiroku), fogrenci);

            fscanf(fadim, "%d", &adim[i]);
        }

        int mevcutindex = 0;
        int yazilankisi = 0;

        for (i = 1; i <= n; i++)
        {
            fseek(fogrenci, ogrenci[mevcutindex], SEEK_SET);
            fgets(satiroku, sizeof(satiroku), fogrenci);

            satiroku[strcspn(satiroku, "\n")] = '\0';

            int mevcutadim = adim[mevcutindex];
            yazdirildi[mevcutindex] = 1;
            yazilankisi++;

            printf("adim %d\n", i);
            printf("%s adim sayisi: %d\n", satiroku, mevcutadim);

            if (yazilankisi >= n)
            {
                break;
            }

            if (mevcutadim % 2 == 0)
            {
                yon = 1;
            }
            else
            {
                yon = -1;
            }

            int kalanadim = mevcutadim;

            while (kalanadim > 0)
            {
                mevcutindex = (mevcutindex + yon) % n;

                if (mevcutindex < 0)
                {
                    mevcutindex += n;
                }

                if (yazdirildi[mevcutindex] == 0)
                {
                    kalanadim--;
                }
            }
        }

        printf("scs\n");
        fclose(fogrenci);
        fclose(fadim);
    }

    return 0;
}
