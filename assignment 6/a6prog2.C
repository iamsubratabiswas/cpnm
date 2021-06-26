/*Write a program in C to create and store information in a text file.*/

#include<file.h>
#include<stdio.h>

#define MAX_SIZE  200
int main()
{
    
    FILE *fp = NULL;
    char buffer[MAX_SIZE] = {0};
    fp = fopen("aticleworld.txt", "w");
    if(fp == NULL)
    {
        printf("Error in creating the file\n");
        exit (1);
    }
    printf("Enter data which you want to store = ");
    if(fgets(buffer,MAX_SIZE,stdin) == NULL)
    {
        printf("Error in reading the input data\n");
        fclose(fp);
        exit (1);
    }
    fwrite(buffer, sizeof(buffer[0]), MAX_SIZE, fp);
    fclose(fp);
    printf("File has been created and saved successfully\n");
    return 0;
}