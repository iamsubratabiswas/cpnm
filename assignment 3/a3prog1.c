/*Write a C program which prints all integers divisible by n between 1 and 100 where value of n is 
provided by the user*/

#include<stdio.h>
int main()
{
    int i,n;
    printf("\nEnter the number : ");
    scanf("%d",&n);
    printf("\nThe numbers divisible by %d are :\n",n);
    for(i=1;i<=100;i++)
    if(i%n==0)
    printf("%d\n",i);
    return 0;
    }
