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

int count = 0;

node *ekle(node *root, int num)
{
    if (root == NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->data = num;
        n->left = NULL;
        n->right = NULL;

        count++;

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

int agactopla(node *agac)
{
    if (agac == NULL)
    {
        return 0;
    }

    return agac->data + agactopla(agac->left) + agactopla(agac->right);
}

void ortkucuksirala(node *agac, float ort)
{
    if (agac == NULL)
    {
        return;
    }

    ortkucuksirala(agac->right, ort);

    if (agac->data < ort)
    {
        printf("%d ", agac->data);
    }

    ortkucuksirala(agac->left, ort);
}

int main()
{
    node *root = NULL;

    root = ekle(root, 20);
    root = ekle(root, 40);
    root = ekle(root, 70);
    root = ekle(root, 10);

    yazdir(root);

    float ort = (float)agactopla(root) / count;

    printf("ort: %.2f\n", ort);

    ortkucuksirala(root, ort);

    return 0;
}
