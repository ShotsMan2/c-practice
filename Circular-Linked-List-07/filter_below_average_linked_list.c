#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void siraliekle(int num)
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

void ortkucuksil()
{
    if (head == NULL)
    {
        return;
    }

    int sum = 0, count = 0;
    float ort;
    node *temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
        count++;
    }
    ort = (float)sum / count;

    printf("ort: %.2f\n", ort);

    node *prevtemp = NULL;
    temp = head;
    while (temp != NULL)
    {
        if (ort > temp->data)
        {
            node *silinecek = temp;
            if (prevtemp == NULL)
            {
                head = temp->next;
            }
            else
            {
                prevtemp->next = temp->next;
            }
            temp = temp->next;
            free(silinecek);
        }
        else
        {
            prevtemp = temp;
            temp = temp->next;
        }
    }
}

int main()
{
    int num, idx1, idx2;

    for (;;)
    {
        printf("sayi gir ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        siraliekle(num);

        listele();
    }

    ortkucuksil();

    listele();

    return 0;
}
