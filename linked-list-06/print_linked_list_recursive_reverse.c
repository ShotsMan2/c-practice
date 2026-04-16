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

void tersyazdir(node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    tersyazdir(temp->next);

    printf("%d ", temp->data);
}

int main()
{
    int num;

    node *head = NULL;
    node *last = NULL;

    for (;;)
    {
        printf("veri gir ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            last = n;
        }
        else
        {
            last->next = n;
            last = n;
        }
    }

    tersyazdir(head);

    return 0;
}
