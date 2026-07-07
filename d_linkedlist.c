#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* insert_begin(struct node *head, int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;

    return head;
}

struct node* insert_end(struct node *head, int value)
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        return newnode;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

struct node* insert_position(struct node *head, int value, int pos)
{
    int i;
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if(pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;

        return newnode;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Position out of range\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    return head;
}

struct node* delete_begin(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    printf("Deleted element is %d\n", temp->data);

    free(temp);

    return head;
}

struct node* delete_end(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->next == NULL)
    {
        printf("Deleted element is %d\n", head->data);
        free(head);
        return NULL;
    }

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    printf("Deleted element is %d\n", temp->data);

    free(temp);

    return head;
}

struct node* delete_position(struct node *head, int pos)
{
    int i;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    temp = head;

    if(pos == 1)
    {
        head = temp->next;

        if(head != NULL)
            head->prev = NULL;

        printf("Deleted element is %d\n", temp->data);

        free(temp);

        return head;
    }

    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Position out of range\n");
        return head;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element is %d\n", temp->data);

    free(temp);

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
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insert_begin(head, 10);
    head = insert_begin(head, 5);
    head = insert_end(head, 20);
    head = insert_position(head, 15, 3);

    display(head);

    search(head, 15);

    head = delete_begin(head);
    display(head);

    head = delete_end(head);
    display(head);

    head = delete_position(head, 2);
    display(head);

    return 0;
}
