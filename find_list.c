#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    int i, key,found=0;
    struct node *newnode, *head=NULL, *p;

    for(i=0;i<10;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter a data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            p=head;
        }
        else
        {
            p->next=newnode;
            p=newnode;
        }
    }
    printf("Enter an element to search:");
    scanf("%d",&key);

    p=head;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            found=1;
            break;
        }
        p=p->next;
    }
    if(found==1)
    {
        printf("The element %d is found",key);
    }
    else
    {
        printf("The element is not found");
    }
    return 0;
}
