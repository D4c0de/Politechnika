#pragma once
#include <iostream>
#include <iomanip> 

void zad5() {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i==0)
            {
                if (j==0)
                {
                    std::cout << std::hex << std::setw(2) << std::setfill(' ') << "   ";
                    continue;
                }
                std::cout << std::hex << std::setw(2) << std::setfill(' ') << j << " ";
            }
            else if(j==0)
            {
                std::cout << std::hex << std::setw(2) << std::setfill(' ') << i << "|";
            }
            else
            {
                std::cout << std::hex << std::setw(2) << std::setfill(' ') << i * j << " ";
            }
            
        }
        if (i==0)
        {
            std::cout << '\n';
            std::cout << "--------------------------------------------";
        }
        std::cout << '\n';
    }

}
