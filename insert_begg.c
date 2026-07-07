#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int i;
	struct node *newnode,*head=NULL,*p=NULL;
	for(i=0;i<5;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
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
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to insert at beginning:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
		
	newnode->next=head;
	head=newnode;
		
	p=head;
	printf("Linked list after insertion:\n");
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL\n");
	return 0;
}
