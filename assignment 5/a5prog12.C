/*Write a program that converts a string like “123” to integer 123. Do not use any string library 
function*/

#include<stdio.h> 
#include<string.h> 

int main() 
{ 
	char Str[1000]; 
	int i; 
    printf("enter num string \n");
	scanf("%s", Str); 
	for (i = 0; Str[i] != '\0'; ++i); 
    int n=i;
    int sum=0,product=1;
    for(i=n-1;i>=0;i--)
    {
        sum+=product*(Str[i]-'0');
        product*=10;
    }
	printf("latest is\n%d",sum);
	return 0; 
} 
