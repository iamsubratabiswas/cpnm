/*Create a structure to specify data on students given below:
 Roll number, Name, Department, Course, Year of joining
 Assume that there are not more than 100 students in the college. 
a. Write a function to print the names of all students who joined in a particular year.
b. Write a function to print the data of a student whose roll number is given*/




#include<stdio.h>
#include<assert.h>
#include<string.h>

typedef long long unsigned int llu;

typedef struct{
    struct student{
        llu roll;
        char name[20];
        char dept[30];
        char course[40];
        int year;
    };

    struct student students[100];
    int size;

    void (*addStud) (llu roll, char* name, char dept[], char course[], int year);
    void (*studInYear) (int year);
    void (*studWithRoll) (llu roll);

} dataBase;

dataBase *currentdBPtr;
void addStudent(llu roll, char* name, char dept[], char course[], int year);
void studentsInYear(int year);
void studentWithRoll(llu roll);

int main() {
    dataBase db;
    db.size=0;
    currentdBPtr=&db;
    db.addStud=addStudent;
    db.studInYear=studentsInYear;
    db.studWithRoll=studentWithRoll;

    int T;
    printf("Enter number of queries: ");
    scanf("%d", &T);
    puts("");

    while(T--){
        printf("Enter: \n\t1 to add student;\n\t2 to find students in year;\n\t3 to search with roll\n\t: ");
        int choice;
        scanf("%d", &choice);
        puts("");

        assert(choice>=1 && choice<=3);

        if(choice==1){//add
            llu roll;
            char name[20];
            char dept[30];
            char course[40];
            int year;

            printf("Enter roll: ");
            scanf("%llu", &roll);
            getchar();

            printf("Enter name: ");
            gets(name);
            //getchar();

            printf("Enter department: ");
            gets(dept);
            //getchar();

            printf("Enter course: ");
            gets(course);
            //getchar();

            printf("Enter year: ");
            scanf("%d", &year);

            db.addStud(roll, name, dept, course, year);
            puts("Successfully added.\n");
        }
        else if(choice==2){//search by year
            int year;
            printf("Enter year: ");
            scanf("%d", &year);

            db.studInYear(year);
            puts("");
        }
        else if(choice==3){//search by roll
            llu roll;
            printf("Enter roll: ");
            scanf("%llu", &roll);

            db.studWithRoll(roll);
            puts("");

        }
    }



}

void addStudent(llu roll, char* name, char dept[], char course[], int year){
    dataBase *dB=currentdBPtr;
    if(dB->size==100){
        printf("Error: Database is full!!\n");
        return;
    }

    assert(roll>0);
    assert(year>0);

    dB->students[dB->size].roll=roll;
    strcpy(dB->students[dB->size].name, name);
    strcpy(dB->students[dB->size].dept, dept);
    strcpy(dB->students[dB->size].course, course);
    dB->students[dB->size].year=year;

    dB->size++;
}

void studentsInYear(int year){
    assert(year>0);

    dataBase *dB=currentdBPtr;
    int i;
    printf("=> Students joined in %d are:\n", year);
    for(i=0; i<dB->size; i++){
        if(dB->students[i].year==year)
            puts(dB->students[i].name);
    }

    puts("");


}

void studentWithRoll(llu mroll){
    assert(mroll>0);

    dataBase *dB=currentdBPtr;
    if(dB->size==0){
        puts("Error: Database empty!\n");

        return;
    }

    int i;

    for(i=0; i<dB->size; i++){
        if(dB->students[i].roll==mroll) {
            printf("=> Data of student with roll %llu :", mroll);
            printf("\n\tName: %s", dB->students[i].name);
            printf("\n\tDepartment: %s", dB->students[i].dept);
            printf("\n\tCourse: %s", dB->students[i].course);
            printf("\n\tYear joined: %d", dB->students[i].year);
            puts("");

            return;
        }

    }

    puts("=> Roll No. not present\n");
    puts("");


}

