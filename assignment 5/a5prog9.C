/*Write a program that reads a line and converts it into all capitals without using any string library 
function. (input string may also contain capital letters*/

#include <stdio.h>
#include<string.h>
int main() {
    char str[100];
    printf("enter line\n");
    scanf("%s",str);
    int i,j,k;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }
    printf("in capital  letter\n%s",str);
	return 0;
}