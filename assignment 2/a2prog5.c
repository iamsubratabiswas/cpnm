/*Input two integer numbers and divide the larger number by the smaller one. Then display the result 
using printf() function as a fractional number first and then as a real valued number. (Example: 9 
divided by 5 shall yield “ 4/5” and “1.8” respectively. )*/

#include<stdio.h>

int main()
{
    int a,b;
    float div;

    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);

   if (a>b)
   div=(float)a/b;
   else
   div=(float)b/a;

   printf("division result = %f",div);
return 0;
}