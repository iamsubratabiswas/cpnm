
/* Write a menu-driven program for accepting values in two square matrix of 3x3 dimension and 
generate their sum, difference and product*/

#include<stdio.h>
#include<conio.h>
int main()
{
 int matA[3][3],matB[3][3],matC[3][3];
 int r,c,k,i;

 for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
  {
    printf("Enter first matrix : ");
    scanf("%d", &matA[r][c]);
  }
 }
 for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
  {
    printf("Enter second matrix : ");
    scanf("%d", &matB[r][c]);
  }
 }
printf("Enter choice \npress 1 for addition \npress 2 for substraction\npress 3 for multplication");
scanf("%d",&i);
switch (i)
{
case 1:
    for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
  {
    matC[r][c]=0;
    for(k=0; k<3;k++)
       matC[r][c] = matA[r][c] + matB[r][c];
  }
 }
  printf("\n New addition matrix : \n"); 
 for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
     printf(" %d",matC[r][c]);
  printf("\n");
 }
    break;
case 2:
for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
  {
    matC[r][c]=0;
    for(k=0; k<3;k++)
       matC[r][c] = matA[r][c] - matB[r][c];
  }
 }
  printf("\n substraction matrix : \n"); 
 for(r=0; r<3; r++)
 {
  for(c=0; c<3; c++)
     printf(" %d",matC[r][c]);
  printf("\n");
 }
 
break;

case 3:
for(r=0; r<3; r++) 
{
      for(c=0;c<3; c++) 
      {
        matC[r][c]=0;
         for (k=0; k<3; k++)
          {
          matC[r][c]= matC[r][c] + matA[r][c]*matB[r][c];
         }
      }
   }
 
   printf("\nMultiplication Of Two Matrices : \n");
   for (r=0; r<3; r++)
    {
      for (c=0; c<3; c++)
       {
         printf(" %d ",matC[r][c]);
      }
      printf("\n");
   }
break;

default :
    break;
}
 return 0;
}