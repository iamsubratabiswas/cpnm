/*Write a C program which accepts number obtained by five students in five subjects. Print the total 
marks obtained by all the students. Also determine the highest total marks*/

#include<stdio.h>
int main()
{

int i,j,max,allsum;
    int stud[5][5];
    int sum[5];
    for(i=0;i<5;i++)
    {
printf("enter marks of studfent%d\n",i);
for(j=0;j<5;j++)
{
scanf("\n%d",&stud[i][j]);
}

   }
//sum
for(i=0;i<5;i++)
{
    sum[i]=0;
    for(j=0;j<5;j++)
    sum[i]=sum[i]+stud[i][j];
    printf("\ntotal marks of studentb%d is = %d",i,sum[i]);
}
allsum=0;
for(i=0;i<5;i++)
{
allsum=allsum+sum[i];
}
printf("\nmarks of all students is= %d",allsum);

//max sum

max=sum[0];
for(i=1;i<5;i++)
{
if(sum[i]>max)
{
max=sum[i];
}
}
 printf("\nmaximum number is = %d",max);
return 0;
}