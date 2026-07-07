#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted\n", value);
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

void isEmpty()
{
    if(front == -1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void isFull()
{
    if(rear == MAX - 1)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();

    dequeue();

    display();

    isEmpty();

    isFull();

    return 0;
}
