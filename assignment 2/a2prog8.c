/*Temperature of a city in Fahrenheit degrees is input through the keyboard. Write a program to 
convert this temperature into Centigrade degrees*/

#include<stdio.h>
int main()
{
    float f,c;
    printf("Enter Temperature in Fahrenheit: ");
    scanf("%f",&f);

    c = (f-32)*5/9;

    printf("The Temperature in Centigrade Degree: %.2f\n",c);
    return (0);
}