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

int main()
{
    int num, sayi, count = 1;

    node *head = NULL;
    node *tail = NULL;

    for (;;)
    {
        printf("Enter a data ");
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
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    printf("Enter a num ");
    scanf("%d", &sayi);

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == sayi)
        {
            printf("%d sayisi %d. siradadir", temp->data, count);
        }
        count++;

        temp = temp->next;
    }

    return 0;
}
