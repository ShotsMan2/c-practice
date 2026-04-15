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
    int sum = 0, count = 0;
    float ort;

    node *n1 = (node *)malloc(sizeof(node));
    n1->data = 1;

    node *n2 = (node *)malloc(sizeof(node));
    n2->data = 10;
    n1->next = n2;

    node *n3 = (node *)malloc(sizeof(node));
    n3->data = 20;
    n2->next = n3;

    node *n4 = (node *)malloc(sizeof(node));
    n4->data = 50;
    n3->next = n4;

    node *n5 = (node *)malloc(sizeof(node));
    n5->data = 90;
    n4->next = n5;

    node *n6 = (node *)malloc(sizeof(node));
    n6->data = 12;
    n5->next = n6;

    node *n7 = (node *)malloc(sizeof(node));
    n7->data = 9;
    n6->next = n7;

    n7->next = NULL;

    node *temp = n1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = n1;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
        count++;
    }

    ort = (float)sum / count;

    printf("\n%.2f\n", ort);

    return 0;
}
