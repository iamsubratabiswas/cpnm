/*Write a C program to print the first n numbers of the Fibonacci sequence. The Fibonacci sequence 
is constructed by adding the last two numbers of the sequence so far to get the next number in the 
sequence. The first and second numbers of the sequence are defined as 0 and 1. We get:
0, 1, 1, 2, 3, 5, 8, 13, 21…*/

#include<stdio.h>
int main()
{
    int i,n,t1=0,t2=1,nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("Fibonacci Series: ");

    for (i=1;i<=n;++i) 
    {
        printf("%d, ",t1);
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }

    return 0;
}