#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int i;
	struct node *newnode,*head=NULL, *tail=NULL, *p=NULL;
	for(i=0;i<5;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL)
		{
			head=newnode;
			tail=head;
		}
		else
		{
			tail->next=newnode;
			tail=newnode;
		}
	}
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to insert at end:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
		
	tail->next=newnode;
	tail=newnode;
		
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
