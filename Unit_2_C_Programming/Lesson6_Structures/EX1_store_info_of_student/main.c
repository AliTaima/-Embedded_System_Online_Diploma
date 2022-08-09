#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    int roll;
    float marks;

};
int main()
{
    struct student student1;
    printf("----------Enter information of students-----------\n");
    printf("Enter name : ");
    fgets(student1.name, 100, stdin);
    printf("Enter roll number: ");
    scanf("%d", &student1.roll);
    printf("Enter marks: ");
    scanf("%f", &student1.marks);
    printf("------------Displaying Information---------------\n");
    printf("Name: %s", student1.name);
    printf("Roll: %d\n", student1.roll);
    printf("Marks: %.2f", student1.marks);
    return 0;
}
