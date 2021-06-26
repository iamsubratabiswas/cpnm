/*Write a C program which accepts a string from user and checks whether it is palindrome or not. Do 
not use any string library function. [Example of a palindrome string: "abcba", "abba"]*/


#include <stdio.h> 
#include <string.h> 
int main() 
{ 
	char Str[1000]; 
	int i; 
    printf("enter string\n");
	scanf("%s", Str); 
	for (i = 0; Str[i] != '\0'; ++i); 
    int n=i;
    int x=1;
    int low=0,high=n-1;
    while(low<high)
    {
        if(Str[low]!=Str[high])
        {
            x=0;
            break;
        }
        low++;
        high--;
    }
    if(x)
    {
        printf("\nPalindrome");
    }
    else{
        printf("\nNot Palindrome");
    }
	return 0; 
} 
