#include <stdio.h>
#include "quadraticroots.h"

int main(){
    QuadraticRootsResult result1 = findroots(1, 7, 5);
    QuadraticRootsResult result2 = findroots(5, 4, 5);
    QuadraticRootsResult result3 = findroots(9, 7, 12);

    printf("x1 is equal to: %f, x2 is equal to: %f, noreal roots: %d", result1.x1, result1.x2, result1.norealroots);
    printf("x1 is equal to: %f, x2 is equal to: %f, noreal roots: %d", result2.x1, result2.x2, result2.norealroots);
    printf("x1 is equal to: %f, x2 is equal to: %f, noreal roots: %d", result3.x1, result3.x2, result3.norealroots);
}