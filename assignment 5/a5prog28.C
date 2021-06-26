/* Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and 
zero otherwise
*/

#include <stdio.h>
#include<string.h>
int func(char arr[])
{
    int n=strlen(arr);
    if(arr[n-1]=='t')
        return 1;
    return 0;
}
int main() {
	char arr[100];
	printf("enter element ");
	scanf("%s",arr);
	int x=func(arr);
	if(x)
	{
	    printf("t is prsent in last");
	}
	else
	{
	    printf("t is prsent not in last");
	}
	return 0;
}