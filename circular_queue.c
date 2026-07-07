#include<stdio.h>
#define MAX 5

int cq[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = value;
    printf("Inserted: %d\n",value);
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
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
        printf("Front element: %d\n", cq[front]);
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    i = front;

    while(i != rear)
    {
        printf("%d ", cq[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", cq[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    peek();

    return 0;
}
