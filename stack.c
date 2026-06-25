#include <stdio.h>
#include <stdlib.h>
#define MS 5
typedef struct stack
{
    int top;
    int arr[MS];
    int size;
} stack;
void init(stack *s)
{
    s->size = 0;
    s->top = -1;
}
void push(stack *s, int x)
{
    if (s->top == MS - 1)
    {
        printf(" stack overflow!\n");
        return;
    }
    s->size++;
    s->arr[++s->top] = x;
}
void display(stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d  ", s->arr[i]);
    }
    printf("\n");
}
void pop(stack *s)
{
    if(s->top==-1)
    {
        printf(" stack underflow!\n");
        return ;
    }
    --s->top;
}
int getSize(stack *s)
{
    int size=s->top+1;
    return size;

}
int gettop(stack *s)
{
    return s->arr[s->top];
}
int main()
{
    stack s;
    init(&s);
    push(&s, 10);
    display(&s);

    push(&s, 20);
    display(&s);

    push(&s, 30);
    display(&s);

    push(&s, 40);
    display(&s);

    push(&s, 50);
    display(&s);

    printf("Size---> %d\n", getSize(&s));
    printf("Top element---> %d\n", gettop(&s));

    push(&s, 60);
    display(&s);
    
    pop(&s);
    display(&s);

    pop(&s);
    display(&s);

    pop(&s);
    display(&s);

    pop(&s);
    display(&s);

    pop(&s);
    display(&s);

    pop(&s);
    display(&s);
}