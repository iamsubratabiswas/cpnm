/* Write a program in C to store n numbers in an array and print the elements using pointers. Also 
compute the sum of all elements of that array using pointers.
*/

#include <stdio.h>

int main() {
	int n,i;
	printf("enter number of elements  \n");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements  ");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}int sum=0;
	for(i=0;i<n;i++)
	{
	    printf("%d",*(&arr[i]));
	    sum+=*(&arr[i]);
	}
	printf("\nsum of all elements=\n %d",sum);
	return 0;
}
