/** Program: A Leader in an array
 *  For a Leader 'L' all elements on right side of 'L' are lessthen
 *  'L'
 *  Input: arr[] = {15,16,3,2,6,1,4}
 *  Output:16,6,4 
 *  (Last array element is always a leader since there is no element
 *  right to last element)
 */  
#include<stdio.h>
/* Time complexcity O(n^2) */
void findLeader(int arr[],int n)
{
    int i,j;
    for(int i=0;i<n;i++)
    {
	for(j=i+1;j<n;j++)
	{
	    if(arr[j] >= arr[i])
		break;
	}
        if(j == n)
	printf("%d is Leader\n",arr[i]);
    }
}

/** Efficient method for finding Leader 
 *  Time complexcity O(n)
 */
void findLeader1(int arr[],int n)
{
    int end = arr[n-1];
    for(int i=n;i>=0;i--)
    {
	if(arr[i]>=end)
	{
	    end = arr[i];
	    printf("%d is Leader",end);
	    printf("\n");
	 }
    }
 }

int main()
{
    int arr[] = {15,16,3,2,6,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    findLeader(arr,n);
    findLeader1(arr,n);

    return 0;
}
