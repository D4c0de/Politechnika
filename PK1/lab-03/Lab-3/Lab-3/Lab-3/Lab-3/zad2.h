#pragma once

#include <iostream>

void zad2() {
	int input;
	std::cin >> input;
	for (size_t i =input; i > 1; i--)
	{
		if (input%i==0)
		{
			std::cout << "liczba nie pierwsza";
			return;
		}
	}
	std::cout << "liczba pierwsza";
}