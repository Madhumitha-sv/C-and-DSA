#include<stdio.h>

int linearSearch(int arr[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    int pos = linearSearch(arr, n, key);

    if(pos == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d\n", pos);
    }

    return 0;
}
