#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned int id;
    char name[75];
    unsigned int age;
} person;

int main()
{
    person student;
    student.id = 1;
    strcpy(student.name, "Nasar Eddaoui");
    student.age = 18;

    person supervisor;
    supervisor.id = 32;
    strcpy(supervisor.name, "Albert Larsson");
    supervisor.age = 45;

    printf("\nSupervisors\nid\t name\t\t age\n");
    printf("%d\t %s\t %d\n", supervisor.id, supervisor.name, supervisor.age);

    printf("\nStudents\nid\t name\t\t age\n");
    printf("%d\t %s\t %d\n", student.id, student.name, student.age);
    return 0;
}