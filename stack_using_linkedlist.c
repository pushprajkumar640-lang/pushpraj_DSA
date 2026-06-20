#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;

Node* init(int x)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node* push(Node *head, int x)
{
    Node *temp = init(x);

    if(head == NULL)
    {
        return temp;
    }

    temp->next = head;
    return temp;
}

void display(Node *head)
{
    if(head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    Node *c = head;

    while(c)
    {
        printf("%d ", c->data);
        c = c->next;
    }

    printf("\n");
}

Node* pop(Node *head)
{
    if(head == NULL)
    {
        printf("Underflow\n");
        return NULL;
    }

    Node *temp = head;
    head = head->next;

    free(temp);

    return head;
}

int main()
{
    Node *head = NULL;

    head = push(head, 10);
    display(head);

    head = push(head, 20);
    display(head);

    head = push(head, 30);
    display(head);

    head = push(head, 40);
    display(head);

    head = pop(head);
    display(head);

    head = pop(head);
    display(head);

    head = pop(head);
    display(head);

    head = pop(head);
    display(head);

    return 0;
}