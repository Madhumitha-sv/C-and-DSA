#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *front)
{
    return (front == NULL);
}

struct node* enQueue(struct node *front, struct node *rear, int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
    }

    return front;
}

struct node* deQueue(struct node *front)
{
    struct node *temp;

    if(isEmpty(front))
    {
        printf("Queue Underflow\n");
        return front;
    }

    temp = front;

    printf("Dequeued element: %d\n", temp->data);

    front = front->next;

    free(temp);

    return front;
}

void peek(struct node *front)
{
    if(isEmpty(front))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

void display(struct node *front)
{
    struct node *p = front;

    if(isEmpty(front))
    {
        printf("Queue is empty\n");
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
    struct node *front = NULL;

    front = enQueue(front, 10);
    front = enQueue(front, 20);
    front = enQueue(front, 30);

    display(front);

    peek(front);

    front = deQueue(front);

    display(front);

    return 0;
}
