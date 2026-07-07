#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* insertbeginning(struct node *head)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf("Inserted at beginning\n");
    return head;
}

struct node* insertend(struct node *head)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(p->next!=NULL)
        p=p->next;
    p->next=newnode;
    printf("Inserted at end\n");
    return head;
}

struct node* insertposition(struct node *head)
{
    int pos,i;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    printf("Enter data:");
    scanf("%d",&newnode->data);
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
        printf("Inserted at position %d\n",pos);
        return head;
    }
    for(i=1;i<pos-1;i++)
    {
        if(p==NULL)
        {
            printf("Position out of range\n");
            free(newnode);
            return head;
        }
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    printf("Inserted at position %d\n",pos);
    return head;
}

struct node* deletebeginning(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    temp=head;
    head=head->next;
    printf("Deleted %d\n",temp->data);
    free(temp);
    return head;
}

struct node* deleteend(struct node *head)
{
    struct node *p=head,*prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        return NULL;
    }
    while(p->next!=NULL)
    {
        prev=p;
        p=p->next;
    }
    printf("Deleted %d\n",p->data);
    prev->next=NULL;
    free(p);
    return head;
}

struct node* deleteposition(struct node *head)
{
    int pos,i;
    struct node *p=head,*prev=NULL;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    printf("Enter position to delete:");
    scanf("%d",&pos);
    if(pos==1)
    {
        struct node *temp=head;
        head=head->next;
        printf("Deleted %d\n",temp->data);
        free(temp);
        return head;
    }
    for(i=1;i<pos;i++)
    {
        if(p==NULL)
        {
            printf("Position out of range\n");
            return head;
        }
        prev=p;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("Position out of range\n");
        return head;
    }
    prev->next=p->next;
    printf("Deleted %d\n",p->data);
    free(p);
    return head;
}

void search(struct node *head)
{
    int key,pos=1;
    struct node *p=head;
    printf("Enter element to search:");
    scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("Element %d found at position %d\n",key,pos);
            return;
        }
        p=p->next;
        pos++;
    }
    printf("Element not found\n");
}

void display(struct node *head)
{
    struct node *p=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked list:\n");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    struct node *head=NULL;
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n7.Search\n8.Display\n9.Exit\n");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&choice);
        if(choice==1)
            head=insertbeginning(head);
        else if(choice==2)
            head=insertend(head);
        else if(choice==3)
            head=insertposition(head);
        else if(choice==4)
            head=deletebeginning(head);
        else if(choice==5)
            head=deleteend(head);
        else if(choice==6)
            head=deleteposition(head);
        else if(choice==7)
            search(head);
        else if(choice==8)
            display(head);
        else if(choice==9)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
