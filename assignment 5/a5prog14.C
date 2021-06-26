/*Write a C program which accepts a string from user and counts the number of words in it. Do not 
use any string library function*/

#include <stdio.h> 

#define OUT 0 
#define IN 1 

unsigned func(char *str) 
{ 
	int state = OUT; 
	unsigned wc = 0;
	while (*str) 
	{ 
		if (*str == ' ' || *str == '\n' || *str == '\t') 
			state = OUT; 
		else if (state == OUT) 
		{ 
			state = IN; 
			++wc; 
		}
		++str; 
	} 
	return wc; 
} 

int main(void) 
{ 
	char str[] = "subrata biswas"; 
	printf("no of words: %u", func(str)); 
	return 0; 
} 
