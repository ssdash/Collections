#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n-1;i++)
    {
	int value = arr[i];
	int hole = i-1;
	while(hole>=0 && arr[hole] > value)
	{
	    arr[hole+1] = arr[hole];
	    hole = hole-1;
	}
	 arr[hole+1] = value;
    }
}
int main()
{
    int arr[] = {4,6,3,7,8,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,len);

    for(int i=0;i<len;i++)
	printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

