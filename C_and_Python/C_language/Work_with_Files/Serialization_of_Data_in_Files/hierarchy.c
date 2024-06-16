#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMPLOYEES 10

typedef struct Employee {
    char name[MAX_NAME_LENGTH];
    int num_slaves;
    struct Employee **slaves;
} Employee;

Employee* suzdaiEmployee(char *name, int num_slaves) {
    Employee *emp = (Employee*)malloc(sizeof(Employee));
    if (emp == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAX_NAME_LENGTH; i++) {
        emp->name[i] = name[i];
        if (name[i] == '\0') break;
    }
    emp->num_slaves = num_slaves;
    emp->slaves = (Employee**)malloc(num_slaves * sizeof(Employee*));
    if (emp->slaves == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_slaves; i++) {
        emp->slaves[i] = NULL;
    }
    return emp;
}

void freeEmployee(Employee *emp) {
    for (int i = 0; i < emp->num_slaves; i++) {
        freeEmployee(emp->slaves[i]);
    }
    free(emp->slaves);
    free(emp);
}

void serializeHierarchy(Employee *director, FILE *file) {
    fwrite(director, sizeof(Employee), 1, file);
    for (int i = 0; i < director->num_slaves; i++) {
        serializeHierarchy(director->slaves[i], file);
    }
}

Employee* deserializeHierarchy(FILE *file) {
    Employee *emp = (Employee*)malloc(sizeof(Employee));
    fread(emp, sizeof(Employee), 1, file);
    emp->slaves = (Employee**)malloc(emp->num_slaves * sizeof(Employee*));
    for (int i = 0; i < emp->num_slaves; i++) {
        emp->slaves[i] = deserializeHierarchy(file);
    }
    return emp;
}

void printHierarchy(Employee *emp, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("%s\n", emp->name);
    for (int i = 0; i < emp->num_slaves; i++) {
        printHierarchy(emp->slaves[i], depth + 1);
    }
}

int main() {
    Employee *director = suzdaiEmployee("Director", 2);
    director->slaves[0] = suzdaiEmployee("Meniger 1", 3);
    director->slaves[1] = suzdaiEmployee("Meniger 2", 3);
    for (int i = 0; i < director->slaves[0]->num_slaves; i++) {
        char name[MAX_NAME_LENGTH];
        sprintf(name, "Employee %d", i + 1);
        director->slaves[0]->slaves[i] = suzdaiEmployee(name, 0);
    }
    for (int i = 0; i < director->slaves[1]->num_slaves; i++) {
        char name[MAX_NAME_LENGTH];
        sprintf(name, "Employee %d", i + 4);
        director->slaves[1]->slaves[i] = suzdaiEmployee(name, 0);
    }

    FILE *file = fopen("employees.bin", "wb");
    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }
    serializeHierarchy(director, file);
    fclose(file);

    file = fopen("employees.bin", "rb");
    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }
    Employee *deserialized_director = deserializeHierarchy(file);
    fclose(file);
    printf("Employee Hierarchy:\n");
    printHierarchy(deserialized_director, 0);

    freeEmployee(director);
    freeEmployee(deserialized_director);

    return 0;
}
