#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int datax, datay;
    char sehir[50];
    struct node *next;
} node;

node *head = NULL;

void yazdir()
{
    node *temp = head;

    while (temp != NULL)
    {
        printf("%s, %d, %d\n", temp->sehir, temp->datax, temp->datay);
        temp = temp->next;
    }

    printf("----------------------\n\n");
}

void SehirEkle(char *sehir, int x, int y, int sira)
{
    int i;

    node *n = (node *)malloc(sizeof(node));
    n->datax = x;
    n->datay = y;
    strcpy(n->sehir, sehir);
    n->next = NULL;

    if (sira == 1)
    {
        n->next = head;
        head = n;
    }
    else
    {
        node *temp = head;

        for (i = 1; i < sira - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp != NULL)
        {
            n->next = temp->next;
            temp->next = n;
        }
        else
        {
            printf("girdiginiz sira bulunmamaktadir.");
            free(n);
        }
    }

    yazdir();
}

void MesafeHesapla(char *sehir1, char *sehir2)
{
    node *temp = head;
    int hesapla = 0;
    double toplammesafe = 0.0;

    while (temp != NULL && temp->next != NULL)
    {
        if (strcmp(temp->sehir, sehir1) == 0 || strcmp(temp->sehir, sehir2) == 0)
        {
            if (hesapla == 0)
            {
                hesapla = 1;
            }
            else
            {
                break;
            }
        }

        if (hesapla == 1)
        {
            double farkx = temp->datax - temp->next->datax;
            double farky = temp->datay - temp->next->datay;

            toplammesafe += sqrt(pow(farkx, 2) + pow(farky, 2));
        }

        temp = temp->next;
    }

    if (toplammesafe > 0)
    {
        printf("\n %s ile %s arasindaki toplam mesafe: %.2f\n\n", sehir1, sehir2, toplammesafe);
    }
    else
    {
        printf("\n girdiginiz sehir veya sehirler bulunamadı\n\n");
    }

    yazdir();
}

int main()
{
    int num, x, y, sira;
    char cop[50], sehir[50], sehir2[50];

    node *tail = NULL;

    for (;;)
    {
        printf(" 1. Dosyadan Oku ve Bagli Liste Olustur\n 2. Sehir Ekle\n 3. iki Sehir Arasi Mesafe Hesapla\n");
        printf(" 4. Sehir Sil\n 5. En Kisa Yolu Bul ve Yeni Bir Bagli Liste Olustur\n 6. Cikis\n");
        printf("1 ile 6 arasinda sayi gir ");
        scanf("%d", &num);

        if (num == 1)
        {
            FILE *fptr;
            fptr = fopen("Sehir.txt", "r");
            if (fptr == NULL)
            {
                printf("basarisiz");
            }
            else
            {
                fgets(cop, sizeof(cop), fptr);
                fgets(cop, sizeof(cop), fptr);
                fgets(cop, sizeof(cop), fptr);

                char tempsehir[50];
                int tempx, tempy;

                while (fscanf(fptr, "%[^,], %d, %d", tempsehir, &tempx, &tempy) == 3)
                {
                    node *n = (node *)malloc(sizeof(node));

                    strcpy(n->sehir, tempsehir);
                    n->datax = tempx;
                    n->datay = tempy;
                    n->next = NULL;

                    if (head == NULL)
                    {
                        head = n;
                        tail = n;
                    }
                    else
                    {
                        tail->next = n;
                        tail = n;
                    }
                }

                printf("basarili\n");
                fclose(fptr);

                yazdir(head);
            }
        }
        else if (num == 2)
        {
            printf("sehri girin ");
            scanf("%s", sehir);

            printf("x i girin ");
            scanf("%d", &x);

            printf("y yi girin ");
            scanf("%d", &y);

            printf("sirayi girin ");
            scanf("%d", &sira);

            SehirEkle(sehir, x, y, sira);
        }
        else if (num == 3)
        {
            printf("hesaplamak istediginiz 1. sehri girin ");
            scanf("%s", sehir);
            printf("hesaplamak istediginiz 2. sehri girin ");
            scanf("%s", sehir2);

            MesafeHesapla(sehir, sehir2);
        }
        else if (num == 4)
        {
        }
        else if (num == 5)
        {
        }
        else if (num == 6)
        {
            printf("islem sonlandirildi\n");
            break;
        }
        else
        {
            printf("Luten 1 ile 6 arasinda giriniz.\n\n");
        }
    }

    return 0;
}
