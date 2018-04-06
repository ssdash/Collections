#include<stdio.h>
#include<stdlib.h>

void heapify(int *arr,int heapsize,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int min;
	if(left<heapsize && arr[left]<arr[i])
	    min = left;
	else
	    min = i;
	if(right<heapsize && arr[right]<arr[min])
	    min = right;

	if(min!= i)
	{
	    int temp = arr[min];
	    arr[min] = arr[i];
	    arr[i] = temp;
	    heapify(arr,heapsize,min);
	}
}

void MinHeap(int *arr,int size)
{
	int i,heapsize;
	heapsize = size;
	for(i = size/2-1;i>=0;i--)
       heapify(arr,heapsize,i);
}

int main()
{
    int len,i;
    int str[] = { 34,3,56,22,1,36,44,67};
    len = sizeof(str)/sizeof(str[0]);
   
    printf("Given array: ");
    for(i=0;i<len;i++)
	printf("%d ", str[i]);
    printf("\n");

    MinHeap(str,len);

    printf("Min Heap: ");
    for(i=0;i<len;i++)
	printf("%d ", str[i]);
    printf("\n");
    return 0;
}
