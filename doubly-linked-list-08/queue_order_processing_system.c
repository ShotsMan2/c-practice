#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    char alan[50];
    char gonderen[50];
    char tarih[20];
    char adres[100];
    char icerik[100];
} node;

node *rear = NULL;
node *front = NULL;

void siparisekle(char *a, char *g, char *t, char *adr, char *i)
{
    node *n = (node *)malloc(sizeof(node));
    strcpy(n->alan, a);
    strcpy(n->gonderen, g);
    strcpy(n->tarih, t);
    strcpy(n->adres, adr);
    strcpy(n->icerik, i);
    n->next = NULL;

    if (rear == NULL)
    {
        rear = n;
        front = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

void siparisgonder()
{
    if (rear == NULL)
    {
        printf("siparis yok\n");
        return;
    }

    node *siparis = front;

    printf("\n--- SIPARIS GONDERILIYOR ---\n");
    printf("Alan: %s\n", siparis->alan);
    printf("Gonderen: %s\n", siparis->gonderen);
    printf("Tarih: %s\n", siparis->tarih);
    printf("Adres: %s\n", siparis->adres);
    printf("Icerik: %s\n", siparis->icerik);
    printf("----------------------------\n");

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }
}

int main()
{

    siparisekle("Ahmet Yilmaz", "Hepsiburada", "10.05.2026", "Konya", "Laptop");
    siparisekle("Mehmet Demir", "Amazon", "11.05.2026", "Ankara", "Klavye");

    siparisgonder(); // Laptop gider

    siparisekle("Elif Can", "N11", "12.05.2026", "Istanbul", "Kitap");

    siparisgonder(); // Klavye gider
    siparisgonder(); // Kitap gider
    siparisgonder(); // Hata verir (Kuyruk bos)

    return 0;
}
