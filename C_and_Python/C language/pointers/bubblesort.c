#include <stdio.h>

typedef int (*CompareFunction)(const void*, const void*);

typedef void (*SwapFunction)(void*, void*);

int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void swapIntegers(void* a, void* b) {
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}

void bubbleSort(void* array, size_t n, CompareFunction compare, SwapFunction swap) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (compare((char*)array + j * sizeof(int), (char*)array + (j + 1) * sizeof(int)) > 0) {
                swap((char*)array + j * sizeof(int), (char*)array + (j + 1) * sizeof(int));
            }
        }
    }
}

int main() {
    int array[] = {4, 2, 8, 5, 1, 7, 6, 3};

    bubbleSort(array, sizeof(array) / sizeof(array[0]), compareAsc, swapIntegers);

    printf("Sorted array in ascending order:\n");
    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubbleSort(array, sizeof(array) / sizeof(array[0]), compareDesc, swapIntegers);

    printf("Sorted array in descending order:\n");
    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}