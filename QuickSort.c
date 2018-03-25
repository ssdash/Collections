#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partationIndex(int *str,int start,int end)
{
    int pIndex,pivot;
    pIndex = start-1;
    pivot = str[end];

    for(int i=start;i<=end-1;i++)
    {
	if(str[i] <= pivot)
	{
	    pIndex++;
	    swap(&str[i],&str[pIndex]);
	}
    }
	swap(&str[pIndex+1],&str[end]);
	return pIndex+1;

}
void quickSort(int *str,int start,int end)
{
    if(start<end)
    {
      int pivot = partationIndex(str,start,end);
      quickSort(str,start,pivot-1);
      quickSort(str,pivot+1,end);
    }
}
int main()
{
    int str[] = {4,5,2,7,8,10,9,6,1,3};
    int len,i;
    len = sizeof(str)/sizeof(str[0]);
    quickSort(str,0,len-1);

    for(i=0;i<len;i++)
	printf("%d ",str[i]);
	printf("\n");
    return 0;
}
