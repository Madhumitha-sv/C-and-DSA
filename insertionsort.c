#include<stdio.h>

void insertionsort(int arr[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
int main()
{
	int i,a[]={23,6,89,17,48};
	int n=sizeof(a)/sizeof(a[0]);
	
	printf("Before sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	
	insertionsort(a,n);
	
	printf("After sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
}
