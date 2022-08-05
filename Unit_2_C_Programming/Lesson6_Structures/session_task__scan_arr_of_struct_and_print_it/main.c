#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
/*
in this code I face some problems
1- when I want to scan a char the char doesn't scan unless I add a white space before the %c
----source
https://stackoverflow.com/questions/29557448/c-program-doesnt-work-scanf-char
(first answer)
2- I use fgets to scan the string and scanf to scan char and numbers, but scanf by default
add a new line after it and the fgets after it and it take this new line as input instead of the name,so
I add getchar() fun to get this new line and fgets work properly
--- source
https://www.codingninjas.com/blog/2021/07/27/solved-the-problem-with-using-fgets-after-scanf/#:~:text=Because%20of%20this%20issue%2C%20the,getchar()%20after%20scanf().
*/

struct student
{
    char name[100];
    int age;
    char degree;
    float gpa;
};

void scan_student(struct student course[], int size);
void print_student(struct student c[], int size);
int main()
{
    struct student course[SIZE];

    scan_student(course, SIZE);
    print_student(course, SIZE);
    return 0;
}
void scan_student(struct student course[], int size)
{
    /*
    This function scanning the students data from the user
    */
    int a;
    for(a = 0; a<size; a++)
    {
        printf("------------Enter Student%d Data------------\n\n", a+1);
        printf("Enter the name for student%d:\n", a+1);
        fgets(course[a].name, 100, stdin);
        printf("Enter the age of student%d: \n", a+1);
        scanf("%d", &course[a].age);
        printf("Enter the gpa of student%d: \n", a+1);
        scanf("%f", &course[a].gpa);
        printf("Enter the degree of student%d: \n", a+1);
        scanf(" %c", &course[a].degree);
        getchar();
    }
}
void print_student(struct student c[], int size)
{
    /*
    This function printing the students data
    */
    int a;
    for(a = 0; a<size; a++)
    {
        printf("\n\n-----------Student%d Data--------------\n\n", a+1);
        printf("Student%d name: %s", a+1, c[a].name);
        printf("Student%d age: %d\n", a+1, c[a].age);
        printf("Student%d gpa: %f\n", a+1, c[a].gpa);
        printf("Student%d degree: %c\n\n", a+1, c[a].degree);
    }
}
