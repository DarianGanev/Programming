#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main(){
    int array[] = {5, 3, 8, 4, 2};
    int n = sizeof(array)/sizeof(array[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    sortArray(array, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}