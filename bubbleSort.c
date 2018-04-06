#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
	for(int j=0;j<n-i-1;j++)
	{
	    if(arr[j]>arr[j+1])
	    {
		int temp = arr[j];
		 arr[j] = arr[j+1];
		 arr[j+1] = temp;
	    }
	}
    }
}
int main()
{
    int arr[] = {4,6,3,7,8,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,len);

    for(int i=0;i<len;i++)
	printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

