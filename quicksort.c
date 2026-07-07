#include<stdio.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int l, int h)
{
	int pivot=arr[l];
	int i=l+1;
	int j=h;
	
	while(i<j)
	{
		while(i<=h && arr[i]<pivot)
		{
			i++;
		}
		while(j>l && arr[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[l],&arr[j]);
	return j;
}

void quicksort(int a[],int l, int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}

int main()
{
	int i;
	int a[]={34,7,90,12,57,98};
	int n=sizeof(a)/sizeof(a[0]);
	
	printf("Before Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	
	quicksort(a,0,n-1);
	
	printf("After Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
