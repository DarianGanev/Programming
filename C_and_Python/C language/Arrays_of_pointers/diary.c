#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 15

typedef struct {
    char *name;
    int *grades;
} Student;

char* inputString() {
    char *buffer = (char *)malloc(MAX_SUBJECT_LENGTH * sizeof(char));
    if (buffer == NULL) {
        printf("Грешка при заделянето на памет.\n");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, MAX_SUBJECT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

void freeStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        free(students[i].name);
        free(students[i].grades);
    }
    free(students);
}

int main() {
    int numSubjects;

    printf("Въведете брой на предметите: ");
    scanf("%d", &numSubjects);
    getchar();

    if (numSubjects <= 0) {
        printf("Грешка: Броят на предметите трябва да е положително число.\n");
        return EXIT_FAILURE;
    }

    char **subjects = (char **)malloc(numSubjects * sizeof(char *));
    if (subjects == NULL) {
        printf("Грешка при заделянето на памет за предметите.\n");
        return EXIT_FAILURE;
    }

    printf("Въведете имената на предметите:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Предмет %d: ", i + 1);
        subjects[i] = inputString();
    }

    int numStudents = 0;
    Student *students = NULL;

    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Въвеждане на ученик\n");
        printf("2. Принтиране на дневника\n");
        printf("3. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                numStudents++;
                students = (Student *)realloc(students, numStudents * sizeof(Student));
                if (students == NULL) {
                    printf("Грешка при заделянето на памет за учениците.\n");
                    return EXIT_FAILURE;
                }

                printf("Въведете име на ученика: ");
                students[numStudents - 1].name = inputString();

                students[numStudents - 1].grades = (int *)malloc(numSubjects * sizeof(int));
                if (students[numStudents - 1].grades == NULL) {
                    printf("Грешка при заделянето на памет за оценките.\n");
                    return EXIT_FAILURE;
                }

                printf("Въведете оценки за ученика %s:\n", students[numStudents - 1].name);
                for (int i = 0; i < numSubjects; i++) {
                    printf("%s: ", subjects[i]);
                    scanf("%d", &students[numStudents - 1].grades[i]);
                }
                getchar();
                break;
            }
            case 2: {
                printf("%*s", MAX_SUBJECT_LENGTH, "");
                for (int i = 0; i < numSubjects; i++) {
                    printf("%s ", subjects[i]);
                }
                printf("\n");

                for (int i = 0; i < numStudents; i++) {
                    printf("%-*s", MAX_SUBJECT_LENGTH, students[i].name);
                    for (int j = 0; j < numSubjects; j++) {
                        printf("%d ", students[i].grades[j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("Изход от програмата.\n");
                break;
            }
            default:
                printf("Невалидна опция.\n");
        }
    } while (choice != 3);

    for (int i = 0; i < numSubjects; i++) {
        free(subjects[i]);
    }
    free(subjects);
    freeStudents(students, numStudents);

    return 0;
}