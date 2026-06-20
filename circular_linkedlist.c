#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node* create(int x)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void display(node *head)
{
    node *c = head;

    while(c->next != head)
    {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("%d ", c->data);
    printf("\n");
}

node* insert_b(node *head, int x)
{
    node *temp = create(x);
    node *last = head;

    while(last->next != head)
    {
        last = last->next;
    }

    temp->next = head;
    last->next = temp;

    return temp;
}

node* insert_l(node *head, int x)
{
    node *temp = create(x);
    node *c = head;

    while(c->next != head)
    {
        c = c->next;
    }

    temp->next = head;
    c->next = temp;

    return head;
}

node* insert_p(node *head, int x, int pos)
{
    node *temp = create(x);
    node *c = head;

    for(int i = 1; i <= pos - 2; i++)
    {
        c = c->next;
    }

    temp->next = c->next;
    c->next = temp;

    return head;
}

node* delete_b(node *head)
{
    node *last = head;

    while(last->next != head)
    {
        last = last->next;
    }

    node *temp = head;
    head = head->next;
    last->next = head;

    free(temp);

    return head;
}

node* delete_l(node *head)
{
    node *c = head;

    while(c->next->next != head)
    {
        c = c->next;
    }

    node *temp = c->next;
    c->next = head;

    free(temp);

    return head;
}

node* delete_p(node *head, int pos)
{
    node *c = head;

    for(int i = 1; i <= pos - 2; i++)
    {
        c = c->next;
    }

    node *temp = c->next;
    c->next = c->next->next;

    free(temp);

    return head;
}

int main()
{
    node *head = create(10);
    node *first = create(20);
    node *second = create(30);
    node *third = create(40);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    display(head);

    head = insert_b(head, 100);
    printf("After Insert Beginning: ");
    display(head);

    head = insert_l(head, 1000);
    printf("After Insert Last: ");
    display(head);

    head = insert_p(head, 999, 3);
    printf("After Insert at Position: ");
    display(head);

    head = delete_b(head);
    printf("After Delete Beginning: ");
    display(head);

    head = delete_l(head);
    printf("After Delete Last: ");
    display(head);

    head = delete_p(head, 4);
    printf("After Delete at Position: ");
    display(head);

    return 0;
}