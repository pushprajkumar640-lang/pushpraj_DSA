#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node ;

node *create(int x)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void display(node *head)
{
    node *curr = head;
    
   while(curr->next!= head)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("%d ",curr->data);
    printf("\n");
}

node *insert_b(node *head, int x)
{
    node *temp = create(x);
    node *curr = head;

    while(curr->next != head)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    temp->next = head;
    head->prev = temp;

    return temp;
}

node *insert_l(node *head,int x)
{
    node *temp = create(x);
    node *curr = head;

    while(curr->next != head)
    {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    temp->next = head;
    head->prev = temp;

    return head;
}

node *insert_p(node *head,int x,int pos)
{
    node *curr = head;
    node *temp = create(x);

    for(int i=1;i<=pos-2;i++)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;

    return head;
}

node *delete_b(node *head)
{
    node *curr = head;

    while(curr->next != head)
    {
        curr = curr->next;
    }

    node *temp = head;
    head = head->next;
    curr->next = head;
    head->prev = curr;

    free(temp);
    return head;
}

node *delete_l(node *head)
{
    node *curr = head;

    while(curr->next != head)
    {
        curr = curr->next;
    }
    node* temp = curr;

    curr = curr->prev;

    curr->next = head;
    head->prev = curr;

    free(temp);
    return head;
}

node *delete_p(node *head,int pos)
{
    node *curr = head;

    for(int i=1; i<=pos-2; i++)
    {
        curr = curr->next;
    }
    node* temp = curr->next;

    curr->next = temp->next;
    temp->next->prev = curr;

    free(temp);
    return head;
}

int main()
{
    node *head = create(4);
    node *first = create(6);
    node *second = create(8);

    node *third = create(9);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    head->prev = third;
    third->prev = second;
    second->prev = first;
    first->prev = head;

    display(head);

    head = insert_b(head,5);
    display(head);

    head = insert_l(head,3);
    display(head);

    head = insert_p(head,7,3);
    display(head);

    head = delete_b(head);
    display(head);

    head = delete_l(head);
    display(head);

    head = delete_p(head,3);
    display(head);

    return 0;
}