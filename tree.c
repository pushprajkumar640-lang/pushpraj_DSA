#include <stdio.h>
#include <stdlib.h>
#define MS 10

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* create(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(node *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int getCountLeaf(node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return getCountLeaf(root->left) + getCountLeaf(root->right);
}

int getCountNonLeaf(node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 0;

    return 1 + getCountNonLeaf(root->left) + getCountNonLeaf(root->right);
}

int main()
{
    node *root = create(10);
    root->left = create(20);
    root->right = create(30);
    root->left->right = create(40);
    root->right->right = create(50);

    printf("Preorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\nCount of Leaf Nodes = %d", getCountLeaf(root));

    printf("\nCount of Non-Leaf Nodes = %d", getCountNonLeaf(root));

    return 0;
}