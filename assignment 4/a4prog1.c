/* Write a program in C to reverse the contents of the elements of an integer array*/

#include<stdio.h>
int main()
{
    int arr[100];
    int i,j,size;
    printf("enter array size");
    scanf("%d",&size);
    printf("enter array elements\n");
    
    for(i=0;i<size;i++)
    {
    scanf("\n%d",&arr[i]);
        }
   
 i=0;
    j=size-1;
    while(i<j)
    {
        int temp;
       temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
    j--;
    
    }
    printf("reversed array is =");
    for(i=0;i<size;i++)
    printf("\n%d",arr[i]);
return 0;
    
}