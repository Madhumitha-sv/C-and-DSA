#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main()
{
	int i,x=10;
	struct node *newnode, *head=NULL ,*p;
	
	for(i=0;i<10;i++)
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
	p=head;
	while(p!=NULL)
	{
		if(x==p->data)
		{
			printf("The element is found in list");
			p=p->next;
		}
	}
		
	return 0;
}


