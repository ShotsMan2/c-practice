#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void listele()
{
    printf("\n");
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void sondankac(int num)
{
    if (head == NULL)
    {
        return;
    }

    int count = 1;
    node *temp = tail;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            break;
        }
        temp = temp->prev;
        count++;
    }

    if (temp == NULL)
    {
        printf("girdigin sayi yok.\n");
    }
    else
    {
        printf("%d sayisi sondan %d. siradadir.\n", num, count);
    }
}

int main()
{
    int num, i;

    for (;;)
    {
        printf("sayi gir ");
        scanf("%d", &num);

        int asal = 1;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                asal = 0;
                break;
            }
        }

        if (num <= 1)
        {
            asal = 0;
        }

        if (asal == 1)
        {
            break;
        }

        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            tail = n;
            n->prev = NULL;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    listele();

    printf("num gir ");
    scanf("%d", &num);

    sondankac(num);

    listele();

    return 0;
}
