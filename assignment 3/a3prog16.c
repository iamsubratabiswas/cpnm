/*Write a C program which accepts 100 integers and displays the counts of positives, negatives and 
zeros entered.*/

#include<stdio.h>

int main()
{
    int i,number,positive=0,negative=0,zero=0;

for(i=1;i<=100;i++)
    {
        printf("Enter number%d= ",i);
        scanf("%d",&number);

        if(number>0)
        {
            positive++;
        }
        else if(number<0)
        {
            negative++;
        }
        else
        {
            zero++;
        }
    }

    printf("\nPositive Numbers :%d\nNegative Numbers :%d\nZero Numbers :%d",
        positive,negative,zero);
 return 0;
}