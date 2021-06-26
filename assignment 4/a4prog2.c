/*Write a program in C to read n number of values in an array. After that, count the total number of 
duplicate elements in that array. Then copy the elements except the duplicate elements of that array 
into another array and display this array in reverse order.*/

#include<stdio.h>
int main()
{
    int s[100];
    int t[100];
    int i,j,k,size,count;
    //set up array
    printf("enter array size");
    scanf("%d",&size);
    printf("enter array elements\n");
    
    for(i=0;i<size;i++)
    {
    scanf("\n%d",&s[i]);
        }
    //print array
    
    printf("array is= ");
    for(i=0;i<size;i++)
    printf("\n%d",s[i]);
    
    //count duplicate
    
    count=0;
   for(i=0;i<size;i++) 
     { 
        for(j=i+1;j<size;j++) 
       { 
             if(s[i]==s[j]) 
              { 
                count++;
                break; 
              } 
       } 
     } 
    
    //print count of duplicate
    
    printf("\n\nTotal number of duplicate elements found in array = %d\n",count);
    
    //copy array without duplicate
    for(i=0;i<size;i++)
    t[i]=s[i];
    
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;)
        {
            if(t[j]==t[i])
            {
                for(k=j;k<size;k++)
                {
                    t[k]=t[k+1];
                }
                size--;
            }
            else
            {
                j++;
            }
        }
    }
    
printf("\ntarget array without duplicate is = "); 
    for(i=0;i<size;i++)
    {
        printf("\n%d",t[i]);
    }
    
   //reverse copied array without duplicate
    
    i=0;
    j=size-1;
    while(i<j)
    {
        int temp;
       temp=t[i];
        t[i]=t[j];
        t[j]=temp;
        i++;
    j--;
    
    }
    printf("\nreversed target array without duplicate is =");
    for(i=0;i<size;i++)
    printf("\n%d",t[i]);
    
    return 0;
    
}