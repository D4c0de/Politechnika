#pragma once
#include <iostream>

double add(double a, double b) {
	return a + b;
}
double subtract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}
double devide(double a, double b) {
	if (b == 0)
	{
		throw std::exception("nie dziel przez zero");
	}
	return a / b;
}

int zad1() {
	double input1, input2;
	std::cout << "wpisz pierwsz¹ liczbê\n";
	std::cin >> input1;
	std::cout << "wpisz drug¹ liczbê\n";
	std::cin >> input2;
	std::cout << "co chcesz zrobiæ\n";
	std::cout << "1. dodawanie\n";
	std::cout << "2.dzielenie\n";
	std::cout << "3.mno¿enie\n";
	std::cout << "4.odejmowanie\n";
	int input3;
	std::cin >> input3;
	double wynik;
	switch (input3)
	{
	case 1:
		wynik = add(input1, input2);
		break;
	case 2:
		try
		{
			wynik = devide(input1, input2);
		}
		catch (const std::exception& x)
		{
			std::cout << x.what();
			return 0;
		}
		break;
	case 3:
		wynik = multiply(input1, input2);
		break;
	case 4:
		wynik = subtract(input1, input2);
		break;
	default:
		break;
	}
	std::cout << wynik << "\n";
}