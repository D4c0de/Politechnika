#pragma once
#include <iostream>
#include <random>

int rand_int(int low, int high)
{
    static std::default_random_engine re{ std::random_device{}() };
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid{};
    return uid(re, Dist::param_type{ low,high });
}
void zad3() {

    int rand = rand_int(1, 10);
    int input;
    
    while (true)
    {
        std::cin >> input;
        if (input==rand)
        {
            
            break;
        }
        else if (input < rand) {
            std::cout << "liczba jest wiêksza";
        }
        else
        {
            std::cout << "liczba jest mniejsza";
        }
    }
    std::cout << "zgad³eœ";
}