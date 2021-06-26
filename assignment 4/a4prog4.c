/*Write a program to find the range of a set of integers entered by the user. Range is the difference 
between the smallest and biggest number in the list*/

#include<stdio.h>
#include<conio.h>
#include<limits.h>

void main()
{
    int num;
    //take the maximum and minimum range for an integer (min=-2147483648 max=2147483647)
    //here we are using c standard library for int data type range <climits> 
    int min = INT_MIN, max = INT_MAX;
    char choice='y';

    do{
    printf("Enter an integer: ");
    scanf("%d", &num);

    //find the maximum and minimum value within input list of numbers
    if(num>min)
        min = num;
    if(num<max)
        max = num;

    //ask for user choice to add another number
    printf("You want to add another integer\ny for yes\n for no\n(y/n)?: ");
    scanf(" %c", &choice); //we have to add a space before '%c'
    }while(choice=='Y'||choice=='y');

printf("Range is %d", (min-max));
getch();
}