#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

void moduler(int mod)
{
    if (head == NULL || mod < 1)
    {
        return;
    }

    if (mod == 1)
    {
        node *temp = head;
        while (temp != NULL)
        {
            node *silinecek = temp;
            temp = temp->next;
            free(silinecek);
        }
        head = NULL;
        return;
    }

    int count = 1;
    node *temp = head;
    node *tempprev = NULL;
    while (temp != NULL)
    {
        if (count % mod == 0)
        {
            node *silinecek = temp;

            tempprev->next = silinecek->next;

            temp = silinecek->next;

            free(silinecek);
        }
        else
        {
            tempprev = temp;
            temp = temp->next;
        }

        count++;
    }
}

int main()
{
    int num, mod;

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

    printf("mod gir ");
    scanf("%d", &mod);

    moduler(mod);

    listele();

    return 0;
}
