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
    int num, count = 1, artis;

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

    printf("artis gir ");
    scanf("%d", &artis);

    node *temp = head;

    while (temp != NULL)
    {
        if (count == artis)
        {
            printf("%d ", temp->data);
            count = 0;
        }

        count++;

        temp = temp->next;
    }

    return 0;
}
