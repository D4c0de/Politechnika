<<<<<<< HEAD
#pragma once
#include <iostream>
int zad3(double a, double b, double c, double* r1, double* r2) {

    double delta, root1, root2;


    delta = b * b - 4 * a * c;


    if (delta > 0) {
        *r1 = (-b + std::sqrt(delta)) / (2 * a);
        *r2 = (-b - std::sqrt(delta)) / (2 * a);
        
        
    }
    else if (delta == 0) {
        *r1 = -b / (2 * a);
    }
    else
    {
        *r1 = -b / (2 * a);
        *r2 = std::sqrt(-delta) / (2 * a);
    }
    return 0;
=======
#pragma once
#include <iostream>
int zad3(double a, double b, double c, double* r1, double* r2) {

    double delta, root1, root2;


    delta = b * b - 4 * a * c;


    if (delta > 0) {
        *r1 = (-b + std::sqrt(delta)) / (2 * a);
        *r2 = (-b - std::sqrt(delta)) / (2 * a);
        
        
    }
    else if (delta == 0) {
        *r1 = -b / (2 * a);
    }
    else
    {
        *r1 = -b / (2 * a);
        *r2 = std::sqrt(-delta) / (2 * a);
    }
    return 0;
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}