#include <stdio.h>

#define ROWS 5
#define COLS 4

void print_table(int rows, int arr[rows][COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    print_table(ROWS, arr);

    return 0;
}