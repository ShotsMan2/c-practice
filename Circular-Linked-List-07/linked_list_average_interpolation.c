#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    float data;
    struct node *next;
} node;

node *head = NULL;

void siraliolustur(float num)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        return;
    }

    if (head->data < num)
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
        printf("%.1f ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void ortal()
{
    float ort;

    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        ort = (temp->data + temp->next->data) / 2.0;

        node *n = (node *)malloc(sizeof(node));
        n->data = ort;

        n->next = temp->next;
        temp->next = n;

        temp = n->next;
    }
}

int main()
{
    float num;

    for (;;)
    {
        printf("sayi gir ");
        scanf("%f", &num);

        if (num == -1)
        {
            break;
        }

        siraliolustur(num);

        listele();
    }

    ortal();

    listele();

    return 0;
}
