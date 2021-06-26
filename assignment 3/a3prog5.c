/*Write a C program to find out sum of the following series.
S=1.2+2.3+3.4+4.5+ ... +n.(n+1)
*/

#include<stdio.h>
int main()
{
    int i,n,sum;
     
    printf("Enter the value of n: ");
    scanf("%d",&n);
     
    sum=0;
     
    for(i=1;i<=n;i++)
        sum=sum+i*(i+1);
     
    printf("Sum of the series is: %d\n",sum);
     
    return 0;
}