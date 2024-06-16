#include "processes.h"
#include <stdio.h>

void displayprocesses() {
    printf("Processes:\n");
    for (int i = 0; i < processescount; ++i) {
        printf("ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}

int main() {
    int option;
    char name[MAX_NAME_LENGTH + 1];
    int processid;

    do {
        printf("\nTask Manager Menu:\n");
        printf("1. Create Process\n");
        printf("2. Display Processes\n");
        printf("3. Stop Process\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", name);

                int newprocessid = createnewprocess(name);

                if (newprocessid == 0) {
                    printf("Error: Maximum number of running processes reached.\n");
                } else {
                    printf("Process created with ID: %d\n", newprocessid);
                }
                break;

            case 2:
                displayprocesses();
                break;

            case 3:
                printf("Enter process ID to stop: ");
                scanf("%d", &processid);
                stopprocess(processid);
                break;

            case 4:
                printf("Exiting Task Manager...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}
