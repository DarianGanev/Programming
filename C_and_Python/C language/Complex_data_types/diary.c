#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[16];
    int class_number;
    double avg_grade;
} Student;

void add_student(Student** students, int* num_students, char* name, int class_number, double avg_grade) {
    *students = (Student*)realloc(*students, (*num_students + 1) * sizeof(Student));
    strncpy((*students)[*num_students].name, name, 16);
    (*students)[*num_students].class_number = class_number;
    (*students)[*num_students].avg_grade = avg_grade;
    (*num_students)++;
}

void print_students(Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Class Number: %d, Average Grade: %.2f\n", students[i].name, students[i].class_number, students[i].avg_grade);
    }
}

int main() {
    int num_students = 0;
    Student* students = NULL;
    char name[16];
    int class_number;
    double avg_grade;

    while (1) {
        printf("Menu:\n1. Add Student\n2. Print Students\n3. Exit\n");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter name (max 15 characters): ");
                scanf("%s", name);
                printf("Enter class number: ");
                scanf("%d", &class_number);
                printf("Enter average grade: ");
                scanf("%lf", &avg_grade);
                add_student(&students, &num_students, name, class_number, avg_grade);
                break;
            case 2:
                print_students(students, num_students);
                break;
            case 3:
                free(students);
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}