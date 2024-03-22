#include <math.h>
#include "quadraticroots.h"

QuadraticRootsResult findroots(double a, double b, double c){
    QuadraticRootsResult result;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0){
        result.norealroots = 1;
    }
    if (discriminant >= 0){
        result.x1 = (-b + discriminant)/(2 * a);
        result.x2 = (-b - discriminant)/(2 * a);
    }
    return result;
}