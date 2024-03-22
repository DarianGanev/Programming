#include "smart_house.h"
#include <stdio.h>

void switchLights(char *rooms, int roomNumber) {
    *rooms ^= (1 << (roomNumber - 1));
}

void printState(char rooms) {
    printf("The light is on in rooms:");

    for (int i = 0; i < 8; ++i) {
        if ((rooms & (1 << i)) != 0) {
            printf(" %d", i + 1);
        }
    }

    printf("\n");
}
