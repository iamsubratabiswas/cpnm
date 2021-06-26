/*Write a C program which accepts a string from user and counts the number of characters in the 
string without using string library functions*/

#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char Str[1000]; 
	int i;
    printf("enter string element\n"); 
	scanf("%s", Str); 
	for (i = 0; Str[i] != '\0'; ++i); 
    int n=i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        if(Str[i]!=' ')
            sum++;
    }
	printf("number of character= %d", sum); 
	return 0; 
} 
