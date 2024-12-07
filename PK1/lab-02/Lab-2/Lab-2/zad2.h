#pragma once
#include <iostream>
int zad2() {
	int input2, input1;

	std::cin >> input1 >> input2;
	int wynik = input2 / input1;
	if (input2 % input1 > 0) {
		wynik++;
	}
	std::cout << "tyle sal:"<<wynik;
	return 1;
}