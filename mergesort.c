#include<stdio.h>

void merge(int arr[],int low,int mid,int high)
{
	int temp[100];
	int i=low;
	int j=mid+1;
	int k=low;
	
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	
	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	
	while(j<=high)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	for(i=low;i<=high;i++)
	{
		arr[i]=temp[i];
	}
}
void mergesort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		
		merge(arr,low,mid,high);
	}
}

int main()
{
	int i;
	int a[]={23,76,9,10,45,93};
	int n=sizeof(a)/sizeof(a[0]);
	
	printf("Before sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	mergesort(a,0,n-1);
	
	printf("After sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}
