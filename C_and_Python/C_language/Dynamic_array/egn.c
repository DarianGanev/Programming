#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10

typedef struct {
    char egn[11];
} Donor;

typedef struct {
    Donor *data;
    size_t size;
    size_t capacity;
} DonorList;

void init(DonorList *list) {
    list->data = (Donor *)malloc(INITIAL_SIZE * sizeof(Donor));
    list->size = 0;
    list->capacity = INITIAL_SIZE;
}

void resize(DonorList *list) {
    list->capacity *= 2;
    list->data = (Donor *)realloc(list->data, list->capacity * sizeof(Donor));
}

void addDonor(DonorList *list, const char *egn) {
    if (list->size == list->capacity) {
        resize(list);
    }
    strcpy(list->data[list->size].egn, egn);
    list->size++;
}

void removeDonor(DonorList *list, const char *egn) {
    int i, j;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->data[i].egn, egn) == 0) {
            for (j = i; j < list->size - 1; j++) {
                strcpy(list->data[j].egn, list->data[j + 1].egn);
            }
            list->size--;
            break;
        }
    }
}

void printDonors(DonorList *list) {
    printf("ЕГН на дарителите:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->data[i].egn);
    }
}

void freeMemory(DonorList *list) {
    free(list->data);
}

int main() {
    DonorList donors;
    init(&donors);

    int choice;
    char egn[11];

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добави дарител\n");
        printf("2. Премахни дарител\n");
        printf("3. Изведи всички дарители\n");
        printf("4. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Въведете ЕГН на дарителя: ");
                scanf("%s", egn);
                addDonor(&donors, egn);
                break;
            case 2:
                printf("Въведете ЕГН на дарителя за премахване: ");
                scanf("%s", egn);
                removeDonor(&donors, egn);
                break;
            case 3:
                printDonors(&donors);
                break;
            case 4:
                freeMemory(&donors);
                printf("Изход от програмата.\n");
                return 0;
            default:
                printf("Невалиден избор!\n");
        }
    }

    return 0;
}
