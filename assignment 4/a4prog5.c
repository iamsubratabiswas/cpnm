/*Write a C program which accepts ten integers from user and prints them in ascending order. Use 
array to store the integers.
*/

#include<stdio.h>

void main()
{
    int arr1[10];
    int n, i, j, tmp;
	
	
       printf("\n\nsort elements of array in ascending order :\n ");
       printf("----------------------------------------------\n");	

       printf("Input  10 elements in the array :\n");
       for(i=0;i<10;i++)
            {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }

    for(i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(arr1[j] <arr1[i])
            {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp;
            }
        }
    }
    printf("\nElements of array in sorted ascending order:\n");
    for(i=0; i<10; i++)
    {
        printf("%d  ", arr1[i]);
    }
	        printf("\n\n");
}