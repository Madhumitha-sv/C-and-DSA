#include<stdio.h>
#define MAX 50

int heap[MAX];
int size=0;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void insertelement(int value)
{
	int current;
	if(size==MAX)
	{
		printf("Heap overflow");
		
	}
	heap[size]=value;
	
	
	current=size;
	size++;
	while(current>0)
	{
		int parent=(current-1)/2;
		if(heap[parent]<heap[current])
		{
			swap(&heap[parent],&heap[current]);
			current=parent;
		}
		else
		{
			break;
		}
	}
}

void deleteelement()
{
	int current;
	if(size==0)
	{
		printf("underflow");
		
	}
	
	heap[0]=heap[size-1];
	size--;
	
	current=0;
	while(1)
	{
		int left=2*current+1;
		int right=2*current+2;
		int largest=current;
		
		if(left<size&&heap[left]>heap[largest])
		{
			largest=left;
		}
		if(right<size&&heap[right]>heap[largest])
		{
			largest=right;
		}
	    if(largest!=current)
	    {
	    	swap(&heap[current],&heap[largest]);
	    	current=largest;
		}
		else
		{
			break;
		}
		
	}
}

void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\n",heap[i]);
		
	}
}

int main()
{
	insertelement(50);
	insertelement(30);
	insertelement(40);
	insertelement(10);
	insertelement(20);
	insertelement(60);
	
	display();
	deleteelement();
	display();
	return 0;
}
