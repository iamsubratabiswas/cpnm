/*Write a C program which accepts basic salary as input and prints the gross salary, which is sum of 
the basic, dearness allowance (60% of basic salary), and house rent allowance (15% of basic salary). */

#include<stdio.h>
int main()
{
    float basic_salary,dallowance,house_rent,gross_salary;
    printf("Enter Basic Salary: ");
    scanf("%f",&basic_salary);

    dallowance=0.6*basic_salary;
    house_rent=0.15*basic_salary;

    gross_salary=basic_salary+dallowance+house_rent;

    printf("\nGross Salary: %.2f", gross_salary);

    return (0);
}