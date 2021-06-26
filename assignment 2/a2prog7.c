/*Accept three integer numbers and find their average. Next display which numbers are below and 
above the average value.*/

#include <stdio.h>
int main()
{
      int a,b,c;
      float avg;
      printf("\tEnter Three integers \n");
      scanf("%d %d %d",&a,&b,&c);
      
      avg=(a+b+c)/3.0;

      printf("\nAverage of Three Numbers : %f\n",avg);

      if(a>avg)
      printf("%d is above average  value\n",a);
    else if(a<avg)
      printf("%d is below  average  value\n",a);
      else
       printf("%d is equal average  value\n",a);

       if(b>avg)
      printf("%d is above average  value\n",b);
    else if(b<avg)
      printf("%d is below average  value\n",b);
      else
       printf("%d is equal average  value\n",b);

      if(c>avg)
      printf("%d is above average  value\n",c);
    else if(c<avg)
      printf("%d is below average  value\n",c);
      else
       printf("%d is equal average  value\n",c);

      return 0;
}