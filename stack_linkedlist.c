#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    return (top == NULL);
}

struct node* push(struct node *top, int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = top;

    top = newnode;

    return top;
}

struct node* pop(struct node *top)
{
    struct node *temp;

    if(isEmpty(top))
    {
        printf("Stack Underflow\n");
        return top;
    }

    temp = top;
    top = top->next;

    printf("Popped element: %d\n", temp->data);

    free(temp);

    return top;
}

void peek(struct node *top)
{
    if(isEmpty(top))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

void display(struct node *top)
{
    struct node *p = top;

    if(isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }

    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
}

int main()
{
	top = push(top, 10);
	top = push(top, 20);
	top = push(top, 30);

	display(top);

	peek(top);

	top = pop(top);

	display(top);
}
