#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

node *ekle(node *root, int num)
{
    if (root == NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->left = NULL;
        n->right = NULL;

        return n;
    }

    if (num < root->data)
    {
        root->left = ekle(root->left, num);
    }
    else if (num > root->data)
    {
        root->right = ekle(root->right, num);
    }

    return root;
}

void yazdir(node *agac)
{
    if (agac == NULL)
    {
        return;
    }

    yazdir(agac->left);

    printf("%d ", agac->data);

    yazdir(agac->right);
}

void aralikyaz(node *agac, int num1, int num2)
{
    if (agac == NULL)
    {
        return;
    }

    aralikyaz(agac->left, num1, num2);

    if (num1 <= agac->data && num2 >= agac->data)
    {
        printf("%d ", agac->data);
    }

    aralikyaz(agac->right, num1, num2);
}

int main()
{
    int num1, num2;

    node *root = NULL;

    root = ekle(root, 20);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 10);

    yazdir(root);

    printf("sayi1 gir ");
    scanf("%d", &num1);

    printf("sayi2 gir ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }

    aralikyaz(root, num1, num2);

    return 0;
}
