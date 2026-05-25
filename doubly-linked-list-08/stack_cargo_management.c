#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    char alan[50];
    char gonderen[50];
    char kargolamaTarihi[20];
    char teslimatAdresi[100];
    int agirlik;
    struct node *next;
} node;

node *top = NULL;

void paketekle(chac)
{
    node *n = (node *)malloc(sizeof(node));
    strcpy(n->agırlık, cjac);
    n->next = NULL;

    n->next = top;

    top = n;
}

void paketicikar(char *isim)
{
    if (top == NULL)
    {
        return;
    }

    int bulundu = 0;
    node *gecicitop = NULL;

    while (top != NULL)
    {
        if (strcmp(isim, top->agırlık) == 0)
        {
            node *silinecek = top;
            top = top->next;
            free(silinecek);

            bulundu = 1;
            break;
        }

        else
        {
            node *tasinan = top;
            top = top->next;

            tasinan->next = gecicitop;
            gecicitop = tasinan;
        }
    }

    if (bulundu == 0)
    {
        printf("girdiginiz isim yok\n");
    }

    while (gecicitop != NULL)
    {
        node *geritasinan = gecicitop;
        gecicitop = gecicitop->next;

        geritasinan->next = top;
        top = geritasinan;
    }
}

int main()
{
    paketekle();

    return 0;
}
