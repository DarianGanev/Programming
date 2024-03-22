// smart_house_main.c

#include "smart_house.h"
#include <stdio.h>

int main() {
    char roomState = 0; // Initialize all rooms with lights off

    int option, roomNumber;

    do {
        printf("\nSmart House Lighting Control Menu\n");
        printf("1. Switch lights in a room\n");
        printf("2. Print state of rooms\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter room number (1-8): ");
                scanf("%d", &roomNumber);
                switchLights(&roomState, roomNumber);
                break;
            case 2:
                printState(roomState);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    return 0;
}
