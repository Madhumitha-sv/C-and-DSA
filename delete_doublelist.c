#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node * create(struct node *head)
{
	struct node *newnode,*p;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
		p=head;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next = newnode;
        newnode->prev = p;
    }
	return head;
}

struct node * deletebyValue(struct node *head)
{
	int del;
	struct node *p=head;
	printf("Enter element to delete:");
	scanf("%d",&del);
	
	while(p!=NULL)
	{
		if(p->data==del)
		{
			if(p->next==NULL && p->prev==NULL)
			{
				head=NULL;
			}
			else if(p->prev==NULL)
			{
				head=p->next;
				head->prev=NULL;
			}
			else if(p->next==NULL)
			{
				p->prev->next=NULL;
			}
			else
			{
				p->prev->next=p->next;
				p->next->prev=p->prev;
			}
			free(p);
			printf("Deleted %d\n",del);
			return head;
		}
		p=p->next;
	}
	printf("Element not found");
	return head;
}

void display(struct node *head)
{
	struct node *p=head;
	if(head=NULL)
	{
		printf("List is empty");
		return;
	}
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL\n");
}

int main()
{
	struct node *head=NULL;
	head=create(head);
	head=create(head);
	head=create(head);
	display(head);
	deletebyValue(head);
	display(head);
}
