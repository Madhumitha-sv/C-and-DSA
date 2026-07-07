#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertbeginning(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    return head;
}

struct node* insertend(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
        return newnode;

    while(p->next != NULL)
        p = p->next;

    p->next = newnode;

    return head;
}

struct node* insertposition(struct node *head, int value, int pos)
{
    int i;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    newnode->data = value;

    if(pos == 1)
    {
        newnode->next = head;
        return newnode;
    }

    for(i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if(p == NULL)
    {
        printf("Position out of range\n");
        free(newnode);
        return head;
    }

    newnode->next = p->next;
    p->next = newnode;

    return head;
}

struct node* deletebeginning(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    temp = head;
    head = head->next;

    printf("Deleted %d\n", temp->data);
    free(temp);

    return head;
}

struct node* deleteend(struct node *head)
{
    struct node *p = head, *prev = NULL;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    while(p->next != NULL)
    {
        prev = p;
        p = p->next;
    }

    printf("Deleted %d\n", p->data);
    prev->next = NULL;
    free(p);

    return head;
}

struct node* deleteposition(struct node *head, int pos)
{
    int i;
    struct node *p = head, *prev = NULL;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(pos == 1)
    {
        head = head->next;
        free(p);
        return head;
    }

    for(i = 1; i < pos && p != NULL; i++)
    {
        prev = p;
        p = p->next;
    }

    if(p == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    prev->next = p->next;
    free(p);

    return head;
}

void search(struct node *head, int key)
{
    int pos = 1;

    while(head != NULL)
    {
        if(head->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        head = head->next;
        pos++;
    }

    printf("Element not found\n");
}

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insertbeginning(head, 10);
    head = insertend(head, 20);
    head = insertposition(head, 15, 2);

    display(head);

    search(head, 15);

    head = deleteposition(head, 2);

    display(head);

    return 0;
}
