#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int egn[12];
    char name[256];
    int age;
    char education[20];
    char employment_status[20];
    char marital_status[20];
} Citizen;

void save_citizen_to_file(Citizen *citizen, FILE *file) {
    fwrite(&citizen->egn, sizeof(int), 12, file);
    fwrite(citizen->name, sizeof(char), 256, file);
    fwrite(&citizen->age, sizeof(int), 1, file);
    fwrite(citizen->education, sizeof(char), 20, file);
    fwrite(citizen->employment_status, sizeof(char), 20, file);
    fwrite(citizen->marital_status, sizeof(char), 20, file);
}

Citizen *load_citizen_from_file(FILE *file) {
    Citizen *citizen = malloc(sizeof(Citizen));
    fread(&citizen->egn, sizeof(int), 12, file);
    fread(citizen->name, sizeof(char), 256, file);
    fread(&citizen->age, sizeof(int), 1, file);
    fread(citizen->education, sizeof(char), 20, file);
    fread(citizen->employment_status, sizeof(char), 20, file);
    fread(citizen->marital_status, sizeof(char), 20, file);
    return citizen;
}

void print_citizen(Citizen *citizen) {
    printf("EGN: %d\n", citizen->egn);
    printf("Name: %s\n", citizen->name);
    printf("Age: %d\n", citizen->age);
    printf("Education: %s\n", citizen->education);
    printf("Employment status: %s\n", citizen->employment_status);
    printf("Marital status: %s\n", citizen->marital_status);
}

int main{
    char filename[50];
    FILE * file = fopen(filename, "rb");
        if (filename == NULL){
            file = fopen(filename, "wb");
        }
}