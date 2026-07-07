#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int i,key;
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
	printf("Enter data to enter:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	
	printf("Insert after element:");
	scanf("%d",&key);
	
	p=head;
	while(p!=NULL)
	{
		if(p->data==key)
		{
			newnode->next=p->next;
			p->next=newnode;
			break;
		}
		p=p->next;
	}

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
