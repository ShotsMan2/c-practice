#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    int num;

    for (;;)
    {
        printf("sayi girin ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        siraliekle(num);

        listele();
    }

    return 0;
}
