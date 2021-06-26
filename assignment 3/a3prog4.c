/*Write a C program to find out sum of the following series.
S=1+2+3+4+ ... +n
*/

#include<stdio.h>
int main()
{
    int i,n,sum;
     
    printf("Enter the value of n: ");
    scanf("%d",&n);
     
    sum=0;
     
    for(i=1;i<=n;i++)
        sum=sum+i;
     
    printf("Sum of the series is: %d\n",sum);
     
    return 0;
}