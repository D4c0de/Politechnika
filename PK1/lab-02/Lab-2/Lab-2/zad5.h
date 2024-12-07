#pragma once
#include <iostream>

void zad5() {

	double a1, a2, b1, b2,c1,c2;	
	std::cout << "1.rownanie :";
	std::cin >> a1 >> b1 >> c1;
	std::cout << "2.rownanie :";
	std::cin >> a2 >> b2 >> c2;

	double W, Wx, Wy;
	W = a1 * b2 - a2 * b1;
	Wx = c1 * b2 - c2 * b1;
	Wy = a1 * c2 - a2 * c1;
	if (W==0)
	{
		std::cout << "uk³ad jest sprzeczny";
		return;
	}
	
	double x, y;
	x = Wx / W;
	y = Wy / W;
	if (Wx == Wy == 0)
	{
		std::cout << "uk³ad jest nie oznaczony";
		return;
	}
	std::cout << "x:" << x << "y:" << y;
}