/*Write a recursive function which returns the sum of individual digits of a number passed as 
argument.*/

#include <stdio.h>
int rec(int n)
{
    if(n==0)
        return 0;
    int sum=0;
    sum+=n%10;
    sum+=rec(n/10);
    return sum;
}
int main() {
	int i,n;
	printf("enter number= ");
	scanf("%d",&n);
	if(n==0)
	{
	    printf("%d",0);
	}
	else
	{
	    int sum=rec(n);
	    printf("sum is= %d",sum);
	}
	return 0;
}