/*Write an algorithm to generate first 100 prime numbers. Also draw the corresponding 
flow chart.
*/
#include<stdio.h>
int func(int n)
{
    int x=1;
    if(n==2)
    {
        return 1;
    }
    if(n==3)
    {
        return 1;
    }
	int i;
	    for(i=2;i<n;i++)
	    {
	        if(n%i==0)
	        {
	            x=0;
	            break;
	        }
	    }
	    return x;
}
int main() {
	int n,i,j,sum=0;
	int x=1;
	for(i=2;i<=1000;i++)
	{
	    if(x==100)
	        break;
	    if(func(i))
	    {
	        x++;
	        printf("%d ",i);
	    }
	}
	
	return 0;
}