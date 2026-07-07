	#include<stdio.h>
	
	void bubble_sort(int list[],int n)
	{
		int i,j,temp;
		int swapped;
		
		for(i=0;i<n-1;i++)
		{
			swapped=0;
			{
				for(j=0;j<n-1-i;j++)
				{
					if(list[j]>list[j+1])
					{
						temp=list[j];
						list[j]=list[j+1];
						list[j+1]=temp;
						
						swapped=1;
					}
				}
				if(swapped==0)
				{
					break;
				}
			}
		}
	}
	
	int main()
	{
		int a[]={50,23,7,49,31};
		int len=sizeof(a)/sizeof(a[0]);
		int i;
		
		bubble_sort(a,len);
		printf("Sorted list:\n");
		
		for(i=0;i<len;i++)
		{
			printf("%d  ",a[i]);
		}
		return 0;
	}
		
