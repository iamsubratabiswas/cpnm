/*Write a C program which accepts a string from user and prints the reverse of the string without 
using string library functions.*/

#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char Str[1000]; 
	int i; 
	scanf("%s", Str); 
	for (i = 0; Str[i] != '\0'; ++i); 
    int n=i;
    int sum=0;
    for(i=n-1;i>=0;i--)
    {
        printf("%c",Str[i]);
    }
	
	return 0; 
} 
