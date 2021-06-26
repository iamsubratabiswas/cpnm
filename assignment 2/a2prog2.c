/*The length and breadth of a rectangle and radius of a circle are input through the keyboard. Write 
a program to calculate the area and perimeter of the rectangle, and the area and circumference of 
the circle.*/


#include<stdio.h>
int main()
{
float a,b,r,area_r,area_c,peri_r,peri_c;
printf("Enter length and breadth of rectangle: ");
scanf("%f %f",&a,&b);

printf("Enter radius: ");
scanf("%f",&r);

area_r=(a*b);
peri_r=((2*a)+(2*b));

area_c=(3.1416*r*r);
peri_c=(3.1416*2*r);

printf("\n\nArea of rectangle = %f",area_r);
printf("\nPerimeter of rectabgle = %f",peri_r);

printf("\n\nArea of the circle = %f",area_c);
printf("\nCircumference of the circle = %f",peri_c);
return 0;
}