<<<<<<< HEAD
#pragma once
#include <iostream>

std::string zad(int* a,int*b) {


	double W, Wx, Wy;
	W= a[0] * b[1] - b[0] * a[1];
	Wx = a[2]* b[1] - b[2] * a[1];
	Wy = a[0]* b[2] - b[0] * a[2];
	if (W == 0)
	{
		return "sprzeczny";
	}

	double x, y;
	x = Wx / W;
	y = Wy / W;
	if (Wx == Wy == 0)
	{
		return "nie oznaczony";
	}
	return "oznaczony";
=======
#pragma once
#include <iostream>

std::string zad(int* a,int*b) {


	double W, Wx, Wy;
	W= a[0] * b[1] - b[0] * a[1];
	Wx = a[2]* b[1] - b[2] * a[1];
	Wy = a[0]* b[2] - b[0] * a[2];
	if (W == 0)
	{
		return "sprzeczny";
	}

	double x, y;
	x = Wx / W;
	y = Wy / W;
	if (Wx == Wy == 0)
	{
		return "nie oznaczony";
	}
	return "oznaczony";
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}