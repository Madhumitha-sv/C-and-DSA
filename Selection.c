#include<stdio.h>

void Selection_sort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		int min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}	
}

int main()
{
	int a[]={55,8,23,49,10};
	int i,n=sizeof(a)/sizeof(a[0]);
	
	Selection_sort(a,n);
	
	printf("Sorted array:\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
