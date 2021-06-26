/*Write an algorithm to determine the sum of individual digits of a given integer. Also 
draw the corresponding flow chart.*/



#include<stdio.h>

int main()
 {
	int n,sum=0;
	scanf("%d",&n);
	while(n!=0)
	{
	    sum+=n%10;
	    n/=10;
	}
	printf("%d",sum);
	return 0;
}