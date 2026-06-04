#include <stdio.h>
#include <stdlib.h>

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

void dugumekle(int num)
{
    if (head == NULL)
    {
        return;
    }
    node *n = (node *)malloc(sizeof(node));
    n->data = num;
    n->next = NULL;

    int sum = 0;
    node *prevtemp = NULL;
    node *temp = head;
    while (temp != NULL)
    {

        sum += temp->data;
        if (sum > num)
        {
            if (prevtemp == NULL)
            {
                n->next = head;
                head = n;
            }
            else
            {
                prevtemp->next = n;
                n->next = temp;
            }
            return;
        }

        prevtemp = temp;
        temp = temp->next;
    }

    if (prevtemp != NULL)
    {
        prevtemp->next = n;
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

    printf("sayi gir ");
    scanf("%d", &num);

    dugumekle(num);

    listele();

    return 0;
}
