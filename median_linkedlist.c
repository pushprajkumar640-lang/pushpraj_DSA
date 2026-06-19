#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void display(node *head)
{
    node *curr = head;

    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void getMedian(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Median Element = %d\n", slow->data);
}

int main()
{
    node *head = create(10);
    node *first = create(20);
    node *second = create(30);
    node *third = create(40);
    node *forth = create(50);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    display(head);

    getMedian(head);

    return 0;
}