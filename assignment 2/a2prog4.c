/*An integer is entered as an input through the keyboard. Write a program to find out whether it is an 
odd number or an even number.
*/


#include<stdio.h>
int main()
{
    int num,result;
    printf("Enter the number\n");
    scanf("%d",&num);
    result=num%2;

    if(result==0)
        printf("Number is even");
    else
        printf("Number is odd");
        return 0;
}