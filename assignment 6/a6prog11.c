/* Write a program which read a C source file having comments (between  and ) and copies it 
another file leaving the comments.*/

#include<stdio.h>

int main() {
    char src[20];
    char dest[20];

    printf("Enter filename for source code: ");
    gets(src);

    FILE* fps=fopen(src, "r");
    while(fps==NULL){
     printf("File doesn't exist. Enter new filename: ");
     gets(src);
     fps=fopen(src, "r");
    }

    printf("Enter destination filename: ");
    gets(dest);

    if(fopen(dest, "r")!=NULL){
        printf("File: %s already exists, overwriting...", dest);
    }

    FILE* fpd=fopen(dest, "w");
    fpd=fopen(dest, "a");
    char c=fgetc(fps);
    int isForSlash=0;
    int isComment=0;
    while(c!=EOF){
        if(isComment){
            if(c=='*'){
                char next=fgetc(fps);
                if(next==EOF){
                    break;
                }
                if(next=='/'){
                    isComment=0;
                    c=getc(fps);
                    continue;
                }
            }
            else {
                c=fgetc(fps);
                continue;
            }
        }

        else{
            if(c=='/'){
                char next=fgetc(fps);
                if(next=='*'){
                    isComment=1;
                    c=fgetc(fps);
                    continue;
                }
                else {
                    fprintf(fpd, "%c", c);
                    if(next==EOF){
                        break;
                    }
                    else{
                        fprintf(fpd, "%c", next);
                        c=fgetc(fps);
                        continue;
                    }
                }
            }
            else {
                fprintf(fpd, "%c", c);
                c=fgetc(fps);
                continue;
            }
        }

    }

    fclose(fps);
    fclose(fpd);

    puts("\n\tSuccessfully copied without the comments!\n");

    return 0;
}
