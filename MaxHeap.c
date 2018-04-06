 26 } 26 } 26 }#include<stdio.h>
#include<stdlib.h>

void maxheapify(int *arr,int heapsize,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest;

    if(left < heapsize && arr[left]>arr[i])
	largest = left;
    else
	largest = i;

    if(right < heapsize && arr[right]>arr[largest])
	largest = right;

    if(largest != i)
    {
	int temp;
	temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
        maxheapify(arr,heapsize,largest);
    }
}

void Heapsort(int *arr,int size)
{
   int  HeapSize = size;
    int HeapLength = HeapSize;
    // Find largest non-leaf index.
    for(int i=((HeapLength/2)-1);i>=0;i--)

	maxheapify(arr,HeapSize,i);
}

int main()
{
    int str[] = {4,45,23,2,6,7,33,32,34,55};
    int len,i;
    len = sizeof(str)/sizeof(str[0]);
    Heapsort(str,len);
    for (i=0;i<len;i++)
    printf("%d ",str[i]);
    printf("\n");
    
    return 0;
}
