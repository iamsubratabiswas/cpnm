/*. A positive integer is entered through the keyboard, write a C function to find the binary equivalent 
of this number using recursion.*/

#include <stdio.h>
void rec(int n)
{
    if(n==0)
        return;
    printf("%d",n%2);
    rec(n/2);
}
int main() {
	int i,n;
	printf("enter number ");
	scanf("%d",&n);
	printf("binary equivalents  is ");
	if(n==0)
	{
	    printf("%d",0);
	}
	else
	{
	    rec(n);
	}
	return 0;
}