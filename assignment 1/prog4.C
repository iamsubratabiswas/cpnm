
/*Write an algorithm to determine whether a given number is prime or not. Also draw the 
corresponding flow chart.*/

#include<stdio.h>

int main() {
	int n,i,j,sum=0;
	scanf("%d",&n);
	if(n==1)
	{
	    printf("no");
	}
	else if(n==2)
	{
	    printf("yes");
	}
	else
	{
	    int x=1;
	    for(i=2;i<n;i++)
	    {
	        if(n%i==0)
	        {
	            x=0;
	            break;
	        }
	    }
	    if(x)
	    {
	        printf("yes");
	    }
	    else
	    {
	        printf("no");
	    }
	}
	return 0;
}