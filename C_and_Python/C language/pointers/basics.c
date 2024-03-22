#include <stdio.h>

int main(){
    double a,b;
    scanf("%ld", &a);
    scanf("%ld", &b);
    
    double * p1 = &a;
    double * p2 = &b;

    printf("Address of p1: %p", p1);
    printf("Address of p2: %p", p2);
    printf("Value of p1: %lf", *p1);
    printf("Value of p2: %lf", *p2);
}