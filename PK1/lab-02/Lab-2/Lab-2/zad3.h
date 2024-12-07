#pragma once
#include <iostream>
#include <cmath>

int zad3() {
    double a, b, c;
    double delta, root1, root2;

    std::cin >> a >> b >> c;

    delta = b * b - 4 * a * c;


    if (delta > 0) {
        root1 = (-b + std::sqrt(delta)) / (2 * a);
        root2 = (-b - std::sqrt(delta)) / (2 * a);
        std::cout << "x1 = " << root1;
        std::cout << "\nx2 = " << root2;
    }
    else if (delta == 0) {
        root1 = -b / (2 * a);
        std::cout << "\nx = " << root1;
    }
    else
    {
        double Re = -b / (2 * a);
        double Im = std::sqrt(-delta) / (2 * a);
        std::cout << "x1 = " << Re << " + " << Im << "i\n";
        std::cout << "x2 = " << Re << " - " << Im << "i\n";
    }
    return 0;
}