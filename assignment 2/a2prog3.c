/*If a three-digit integer is input through the keyboard, write a program to calculate the sum of its 
digits. (Hint: Use the modulo operator ‘%’)*/


#include<stdio.h>
int main()
{
   int n,t,sum=0,remainder,i;

   printf("Enter an 3 digit integer\n");
   scanf("%d",&n);

   t=n;

   for(i=1;i<=3;i++)
   {
      remainder=t%10;
      sum=sum+remainder;
      t=t/10;
   }
printf("Sum of last 3 digits of %d = %d\n",n,sum);
return 0;
}