#include <stdio.h>
#include <stdlib.h>

#define ERROR_EXIT_CODE 1

void Menu() {
    printf("\nMenu:\n");
    printf("1. Average grade\n");
    printf("2. Add new grade\n");
    printf("3. Delete grade\n");
    printf("4. Exit\n");
}

void Error(const char *error) {
    printf("Error: %s\n", error);
    exit(ERROR_EXIT_CODE);
}

int main() {
    int *grades = NULL;
    int numGrades = 0;

    printf("Enter number of grades: ");
    scanf("%d", &numGrades);

    if (numGrades <= 0) {
        Error("Ammount of grades should be greater than zero.\n");
    }

    grades = (int *)malloc(numGrades * sizeof(int));
    if (grades == NULL) {
        Error("Error!\n");
    }

    printf("Enter grades:\n");
    for (int i = 0; i < numGrades; i++) {
        scanf("%d", &grades[i]);
    }

    int choice;
    do {
        Menu();
        printf("Choose option:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                double average = 0;
                for (int i = 0; i < numGrades; i++) {
                    average += grades[i];
                }
                average /= numGrades;
                printf("Average grade: %.2lf\n", average);
                break;

            case 2:
                numGrades++;
                grades = (int *)realloc(grades, numGrades * sizeof(int));
                if (grades == NULL) {
                    Error("Error!\n");
                }
                printf("Enter new grade:\n");
                scanf("%d", &grades[numGrades - 1]);
                break;

            case 3:
                if (numGrades > 0) {
                    numGrades--;
                    grades = (int *)realloc(grades, numGrades * sizeof(int));
                    if (grades == NULL && numGrades > 0) {
                        Error("Error!\n");
                    }
                } else {
                    printf("No grades to delete.\n");
                }
                break;

            case 4:
                free(grades);
                exit(0);

            default:
                printf("Error!\n");
        }
    } while (1);

    return 0;
}
