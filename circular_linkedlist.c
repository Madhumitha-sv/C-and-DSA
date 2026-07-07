#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insertBegin(struct Node *head, int val)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;

    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *tail = head;

    while(tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
    head = newNode;

    return head;
}

struct Node* insertEnd(struct Node *head, int val)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;

    if(head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *tail = head;

    while(tail->next != head)
        tail = tail->next;

    tail->next = newNode;
    newNode->next = head;

    return head;
}

struct Node* insertAtPos(struct Node *head, int val, int pos)
{
    int i;

    if(pos == 0)
        return insertBegin(head, val);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;

    struct Node *temp = head;

    for(i = 0; i < pos - 1; i++)
    {
        temp = temp->next;

        if(temp == head)
        {
            printf("Position out of range\n");
            free(newNode);
            return head;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteBegin(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->next == head)
    {
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *tail = head;

    while(tail->next != head)
        tail = tail->next;

    struct Node *temp = head;

    head = head->next;
    tail->next = head;

    printf("Deleted %d\n", temp->data);

    free(temp);

    return head;
}

struct Node* deleteEnd(struct Node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->next == head)
    {
        printf("Deleted %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node *prev = head;

    while(prev->next->next != head)
        prev = prev->next;

    struct Node *tail = prev->next;

    prev->next = head;

    printf("Deleted %d\n", tail->data);

    free(tail);

    return head;
}

struct Node* deleteValue(struct Node *head, int val)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->data == val)
        return deleteBegin(head);

    struct Node *prev = head;
    struct Node *curr = head->next;

    while(curr != head)
    {
        if(curr->data == val)
        {
            prev->next = curr->next;

            printf("Deleted %d\n", val);

            free(curr);

            return head;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("%d not found\n", val);

    return head;
}

void search(struct Node *head, int val)
{
    struct Node *temp;
    int pos = 0;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while(temp->next != head)
    {
        if(temp->data == val)
        {
            printf("%d found at position %d\n", val, pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    if(temp->data == val)
    {
        printf("%d found at position %d\n", val, pos);
        return;
    }

    printf("%d not found\n", val);
}

void display(struct Node *head)
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while(temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> (HEAD)\n", temp->data);
}

int main()
{
    struct Node *head = NULL;

    head = insertBegin(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertAtPos(head, 15, 1);

    display(head);

    search(head, 20);

    head = deleteBegin(head);
    display(head);

    head = deleteEnd(head);
    display(head);

    head = deleteValue(head, 20);
    display(head);

    return 0;
}
