#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[],int n)
{
    int j,iMin,temp;
    for(int i=0;i<n-1;i++)
    {
	iMin = i;
	// Run the loop and find the Minimum index value.
	for(j=i+1;j<n;j++)
	{
	    if(arr[j]<arr[iMin])
	    {
		iMin = j;
	    }
	}
	temp = arr[i];
	arr[i] = arr[iMin];
	arr[iMin] = temp;
    }
}

int main()
{
    int arr[] = {34,5,7,12,33,21,9,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,len);

    for(int i=0;i<len;i++)
	printf("%d ",arr[i]);

    printf("\n");
}
