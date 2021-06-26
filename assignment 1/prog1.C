/*1. Write an algorithm to determine maximum of three numbers. Also draw the 
corresponding flow chart.*/




#include<stdio.h>
int main()
 {
	int n1,n2,n3,i,j;
	printf("enter 3 numbers\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);
	int maxi=n1;
	if(n2>maxi)
	{
	    maxi=n2;
	}
	if(n3>maxi)
	{
	    maxi=n3;
	}
	printf("largest=%d",maxi);
	return 0;
}