#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct student
{
    char name[100];
    int roll;
    float marks;
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
    printf("---------------------Enter information of students-----------------------------\n\n");
    for(a = 0; a<size; a++)
    {
        printf("------------Enter Student%d Data------------\n\n", a+1);
        printf("Enter the name for student%d:\n", a+1);
        fgets(course[a].name, 100, stdin);
        printf("Enter the roll of student%d: \n", a+1);
        scanf("%d", &course[a].roll);
        printf("Enter the marks of student%d: \n", a+1);
        scanf("%f", &course[a].marks);
        getchar();// to scape the new line that make by default by scanf, to protect fgets function
    }
}
void print_student(struct student c[], int size)
{
    /*
    This function printing the students data
    */
    int a;
    printf("---------------------Displaying information of students-----------------------------\n\n");
    for(a = 0; a<size; a++)
    {
        printf("\n\n-----------Student%d Data--------------\n\n", a+1);
        printf("Student%d name: %s", a+1, c[a].name);
        printf("Student%d roll: %d\n", a+1, c[a].roll);
        printf("Student%d marks: %.1f\n", a+1, c[a].marks);
    }
}
