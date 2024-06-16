#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char egn[13];
    char name[256];
    int age;
    char education[20];
    char employment_status[20];
    char marital_status[20];
} Citizen;

void save_citizen_to_file(Citizen *citizen, FILE *file) {
    fwrite(citizen, sizeof(Citizen), 1, file);
}

Citizen *load_citizen_from_file(FILE *file) {
    Citizen *citizen = malloc(sizeof(Citizen));
    if (fread(citizen, sizeof(Citizen), 1, file) != 1) {
        free(citizen);
        return NULL;
    }
    return citizen;
}

void print_citizen(Citizen *citizen) {
    printf("EGN: %s\n", citizen->egn);
    printf("Name: %s\n", citizen->name);
    printf("Age: %d\n", citizen->age);
    printf("Education: %s\n", citizen->education);
    printf("Employment status: %s\n", citizen->employment_status);
    printf("Marital status: %s\n", citizen->marital_status);
}

int main() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        file = fopen(filename, "wb+");
    }

    int choice;
    while (1) {
        printf("1. Add citizen\n");
        printf("2. Print citizens\n");
        printf("3. Delete citizen\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Citizen citizen;
                printf("Enter EGN: ");
                scanf("%s", citizen.egn);
                printf("Enter name: ");
                scanf("%s", citizen.name);
                printf("Enter age: ");
                scanf("%d", &citizen.age);
                printf("Enter education (e.g. No education, Primary, Secondary, Higher): ");
                scanf("%s", citizen.education);
                printf("Enter employment status (e.g. Unemployed, Employed): ");
                scanf("%s", citizen.employment_status);
                printf("Enter marital status (e.g. Unmarried, Married): ");
                scanf("%s", citizen.marital_status);
                save_citizen_to_file(&citizen, file);
                break;
            }
            case 2: {
                rewind(file);
                Citizen *citizen;
                while ((citizen = load_citizen_from_file(file))!= NULL) {
                    print_citizen(citizen);
                    free(citizen);
                }
                break;
            }
            case 3: {
                char egn[13];
                printf("Enter EGN to delete: ");
                scanf("%s", egn);
                FILE *tempFile = fopen("citizen.bin", "wb");
                rewind(file);
                Citizen *citizen;
                while ((citizen = load_citizen_from_file(file))!= NULL) {
                    if (strcmp(citizen->egn, egn) != 0) {
                        save_citizen_to_file(citizen, tempFile);
                    }
                    free(citizen);
                }
                fclose(file);
                fclose(tempFile);
                remove(filename);
                rename("citizen.bin", filename);
                file = fopen(filename, "rb+");
                break;
            }
            case 4: {
                fclose(file);
                exit(0);
            }
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;    
}