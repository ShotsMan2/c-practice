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

void swaps(int idx1, int idx2)
{
    if (head == NULL || idx1 == idx2 || idx1 < 1 || idx2 < 1)
    {
        return;
    }

    if (idx1 > idx2)
    {
        int temp = idx1;
        idx1 = idx2;
        idx2 = temp;
    }

    int i;

    node *curr1 = head;
    node *prev1 = NULL;
    for (i = 1; i < idx1 && curr1 != NULL; i++)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    node *curr2 = head;
    node *prev2 = NULL;
    for (i = 1; i < idx2 && curr2 != NULL; i++)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL)
    {
        printf("girdigin index yok.\n");
        return;
    }

    if (curr1->next == curr2)
    {
        if (prev1 != NULL)
        {
            prev1->next = curr2;
        }
        else
        {
            head = curr2;
        }

        curr1->next = curr2->next;

        curr2->next = curr1;
    }
    else
    {
        if (prev1 != NULL)
        {
            prev1->next = curr2;
        }
        else
        {
            head = curr2;
        }

        prev2->next = curr1;

        node *temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
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

    printf("yer degistirecegin indexi gir ");
    scanf("%d", &idx1);

    printf("yer degistirecegin indexi gir ");
    scanf("%d", &idx2);

    swaps(idx1, idx2);
    listele();

    return 0;
}
