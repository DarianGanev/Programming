#include <stdio.h>

void swap(void *a, void *b){
    int * p1 = (int *)a;
    int * p2 = (int *)b;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}

int main(){
    int a,b; 
    a = 7;
    b = 5;

    swap(&a, &b);

    printf("a = %d, b = %d\n",&a, &b);
}