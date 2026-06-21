#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void siraliolustur(int num)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        return;
    }

    if (head->data <= num)
    {
        n->next = head;
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL && temp->next->data > num)
    {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
}

void listele()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void guncelle(int yeninum, int guncel)
{
    if (head == NULL)
    {
        printf("once sayi gir.\n");
        return;
    }
    int uygun = 0;

    node *temp = head;
    node *tempprev = NULL;
    while (temp != NULL)
    {
        if (temp->data == guncel)
        {
            uygun = 1;
            break;
        }
        tempprev = temp;
        temp = temp->next;
    }

    if (uygun == 0)
    {
        printf("girdiginiz sayi yok.\n");
        return;
    }

    if (tempprev == NULL)
    {
        head = temp->next;
    }
    else
    {
        tempprev->next = temp->next;
    }

    free(temp);

    siraliolustur(yeninum);
}

int main()
{
    int num, guncel, yeninum;

    for (;;)
    {
        printf("sayi girin ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        siraliolustur(num);

        listele();
    }

    printf("guncel gir ");
    scanf("%d", &guncel);

    printf("yeninum gir ");
    scanf("%d", &yeninum);

    guncelle(yeninum, guncel);

    listele();

    return 0;
}
