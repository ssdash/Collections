#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int *left,int leftCount,int *right,int rightCount)
{
   int i=0,j=0,k=0;
   while(i<leftCount && j<rightCount)
   {
       if (left[i] < right[j])
           arr[k++] = left[i++];
       else
	   arr[k++] = right[j++];
   }
   while(i<leftCount)
       arr[k++] = left[i++];
   
   while(j<rightCount)
       arr[k++] = right[j++];
}


void MergeSort(int *arr,int len)
{
    int i,mid,*left,*right;
    if(len<2)
	return;
	
        mid = len/2;
	
	left = (int*)malloc(mid*sizeof(int));
	right = (int*)malloc((len-mid)*sizeof(int));
        

        for(i=0;i<mid;i++)
	    left[i] = arr[i];
	
	for(i=mid;i<len;i++)
	    right[i-mid] = arr[i];

	MergeSort(left,mid);
	MergeSort(right,len-mid);
	merge(arr,left,mid,right,len-mid);

	free(left);
	free(right);
}

int main()
{
    int myArray[] = {3,5,1,7,6,10,9,8,4,2};
    int len,i;
    len = sizeof(myArray)/sizeof(myArray[0]);
    MergeSort(myArray,len);

	for(i=0;i<len;i++)
	  printf("%d ",myArray[i]);

	printf("\n");
    return 0;
}
