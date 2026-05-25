#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
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

    if (num > root->data)
    {
        root->right = ekle(root->right, num);
    }
    else if (num < root->data)
    {
        root->left = ekle(root->left, num);
    }

    return root;
}

void yaz(node *agac)
{
    if (agac == NULL)
    {
        return;
    }

    yaz(agac->left);

    printf("%d ", agac->data);

    yaz(agac->right);
}

int main()
{
    node *root = NULL;

    root = ekle(root, 20);
    root = ekle(root, 30);
    root = ekle(root, 10);
    root = ekle(root, 70);

    yaz(root);

    return 0;
}
