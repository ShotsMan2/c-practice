#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    float x;
    float y;
    char sehir[50];
    struct node *next;
} node;

node *head = NULL;

void listele()
{
    printf("\n\n");

    node *temp = head;
    printf("%s\t\t%.1f\t\t%.1f\n", temp->sehir, temp->x, temp->y);
    temp = temp->next;

    while (temp != head)
    {
        printf("%s\t\t%.1f\t\t%.1f\n", temp->sehir, temp->x, temp->y);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int num, i, n, j, k;
    char sehir[15][50], yenisehir[50], gecicisehir[50];
    float x[15], y[15], toplammesafe = 0.0, yenix, yeniy, gecicix, geciciy, toplammesafe2 = 0.0, eskimesafe1, eskimesafe2, eskimesafe3, eskimesafe4, yenimesafe1, yenimesafe2, yenimesafe3, yenimesafe4;

    srand(time(NULL));

    for (;;)
    {
        printf(" 1) Listeyi Olustur\n 2) N Kez Random 2 Sehir Yer Degistir\n 3) Sehir ekle\n 4) Tur Goruntule ve Hesapla\n");
        printf(" 5) cikis\n");
        printf("1 ile 5 arasinda sayi gir ");
        scanf("%d", &num);
        printf("\n");

        if (num == 1)
        {
            FILE *fptr;
            fptr = fopen("Sehirler.txt", "r");
            if (fptr == NULL)
            {
                printf("unsc\n");
            }
            else
            {
                int ziyaret[20] = {0}, sehirsayisi = 0;

                while (fscanf(fptr, "%[^,],%f,%f", sehir[sehirsayisi], &x[sehirsayisi], &y[sehirsayisi]) == 3)
                {
                    sehirsayisi++;
                }

                fclose(fptr);

                node *tail = NULL;
                int songidilenindex = -1;

                for (i = 0; i < sehirsayisi; i++)
                {
                    if (strcmp(sehir[i], "İstanbul") == 0)
                    {
                        node *n = (node *)malloc(sizeof(node));
                        strcpy(n->sehir, sehir[i]);
                        n->x = x[i];
                        n->y = y[i];

                        head = n;
                        tail = n;

                        ziyaret[i] = 1;
                        songidilenindex = i;
                        break;
                    }
                }

                int eklenen = 1;

                while (eklenen < sehirsayisi)
                {
                    int enyakinindex = -1;
                    float minmesafe = 99999.0;

                    for (i = 0; i < sehirsayisi; i++)
                    {
                        if (ziyaret[i] == 0)
                        {
                            float mesafe = fabs(x[songidilenindex] - x[i]) + fabs(y[songidilenindex] - y[i]);

                            if (mesafe < minmesafe)
                            {
                                minmesafe = mesafe;
                                enyakinindex = i;
                            }
                        }
                    }

                    node *n = (node *)malloc(sizeof(node));
                    n->x = x[enyakinindex];
                    n->y = y[enyakinindex];
                    strcpy(n->sehir, sehir[enyakinindex]);

                    tail->next = n;
                    tail = n;

                    ziyaret[enyakinindex] = 1;
                    songidilenindex = enyakinindex;
                    eklenen++;
                }

                tail->next = head;

                printf("scs\n\n");

                listele();
            }
        }
        else if (num == 2)
        {
            if (head == NULL)
            {
                printf("Liste bos. Lutfen once 1. secenek ile listeyi doldurun.\n\n");
                continue;
            }

            n = rand() % 20 + 5;

            node *temp = head;
            node *iter = head;
            node *sondanonceki = NULL;
            do
            {
                sondanonceki = temp;
                temp = temp->next;
            } while (temp->next != head);

            temp->next = iter->next;
            sondanonceki->next = iter;
            iter->next = temp;

            head = temp;
            printf("1. islem: 1. ve 10. sehir swap:");

            listele();

            for (i = 0; i < n - 1; i++)
            {
                int random1 = rand() % 12 + 1;
                int random2 = rand() % 12 + 1;

                if (random1 == random2)
                {
                    i--;
                    continue;
                }

                if (random1 > random2)
                {
                    int temprand = random1;
                    random1 = random2;
                    random2 = temprand;
                }

                temp = head;
                iter = head;
                node *prevtemp = NULL;
                node *previter = NULL;

                toplammesafe = 0.0;
                do
                {
                    toplammesafe += fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y);
                    temp = temp->next;
                } while (temp != head);

                for (j = 0; j < random1; j++)
                {
                    prevtemp = temp;
                    temp = temp->next;
                }

                for (k = 0; k < random2; k++)
                {
                    previter = iter;
                    iter = iter->next;
                }

                if (temp->next == iter || iter->next == temp)
                {
                    i--;
                    continue;
                }

                node *iterator = head;
                toplammesafe2 = 0.0;

                eskimesafe1 = fabs(prevtemp->x - temp->x) + fabs(prevtemp->y - temp->y);
                eskimesafe2 = fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y);
                eskimesafe3 = fabs(previter->x - iter->x) + fabs(previter->y - iter->y);
                eskimesafe4 = fabs(iter->x - iter->next->x) + fabs(iter->y - iter->next->y);

                yenimesafe1 = fabs(prevtemp->x - iter->x) + fabs(prevtemp->y - iter->y);
                yenimesafe2 = fabs(iter->x - temp->next->x) + fabs(iter->y - temp->next->y);
                yenimesafe3 = fabs(previter->x - temp->x) + fabs(previter->y - temp->y);
                yenimesafe4 = fabs(temp->x - iter->next->x) + fabs(temp->y - iter->next->y);

                toplammesafe2 = toplammesafe - eskimesafe1 - eskimesafe2 - eskimesafe3 - eskimesafe4 + yenimesafe1 + yenimesafe2 + yenimesafe3 + yenimesafe4;

                if (toplammesafe > toplammesafe2)
                {
                    node *temparka = temp->next;
                    node *iterarka = iter->next;

                    prevtemp->next = iter;
                    iter->next = temparka;

                    previter->next = temp;
                    temp->next = iterarka;

                    if (head == temp)
                    {
                        head = iter;
                    }
                    else if (head == iter)
                    {
                        head = temp;
                    }
                    printf("\n%d. islem: %d ve %d. sehir swap: Tur uzunlugu azaldi. Islem yapildi.", i + 2, j + 1, (k + 1) % 10);
                }
                else
                {
                    printf("\n%d. islem: %d ve %d. sehir swap: Tur uzunlugu artti. Islem yapilmadi.", i + 2, j + 1, (k + 1) % 10);
                }

                listele();
            }
        }
        else if (num == 3)
        {
            if (head == NULL)
            {
                printf("Liste bos. Lutfen once 1. secenek ile listeyi doldurun.\n\n");
                continue;
            }

            printf("eklemek istediginiz sehri girin ");
            scanf("%s", yenisehir);
            printf("x i girin ");
            scanf("%f", &yenix);
            printf("y yi girin ");
            scanf("%f", &yeniy);

            float mevcuttur = 0.0;
            node *temp = head;
            do
            {
                mevcuttur += (fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y));
                temp = temp->next;
            } while (temp != head);

            temp = head;
            node *eniyidurak = NULL;
            float minyenitur = 99999.0;

            do
            {
                float eskimesafe = fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y);

                float artimesafe = fabs(yenix - temp->x) + fabs(yeniy - temp->y);
                float artimesafe2 = fabs(yenix - temp->next->x) + fabs(yeniy - temp->next->y);

                float deneme = mevcuttur - eskimesafe + artimesafe2 + artimesafe;

                printf("%s ile %s arasina eklenirse tur: %.1f birim", temp->sehir, temp->next->sehir, deneme);

                if (deneme < minyenitur)
                {
                    minyenitur = deneme;
                    eniyidurak = temp;
                }

                temp = temp->next;

            } while (temp != head);

            node *n = (node *)malloc(sizeof(node));
            n->x = yenix;
            n->y = yeniy;
            strcpy(n->sehir, yenisehir);

            n->next = eniyidurak->next;
            eniyidurak->next = n;

            listele();
        }
        else if (num == 4)
        {
            if (head == NULL)
            {
                printf("Liste bos. Lutfen once 1. secenek ile listeyi doldurun.\n\n");
                continue;
            }

            listele();

            node *temp = head;
            toplammesafe += fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y);
            temp = temp->next;

            toplammesafe = 0.0;

            while (temp != head)
            {
                toplammesafe += fabs(temp->x - temp->next->x) + fabs(temp->y - temp->next->y);
                temp = temp->next;
            }

            printf("Tur uzunlugu: %.1f birim\n\n", toplammesafe);
        }
        else if (num == 5)
        {
            break;
        }
    }

    return 0;
}
