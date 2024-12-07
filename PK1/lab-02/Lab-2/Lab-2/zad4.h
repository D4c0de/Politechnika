#pragma once

#include <iostream>
#include <cmath>

class punkt
{
public:
	punkt();
	int x;
	int y;
	~punkt();
	double odleglosc(punkt);
private:


};

punkt::punkt()
{
	std::cout << "podaj x,y\n";
	std::cin >> x >> y;
}

punkt::~punkt()
{
}
inline double punkt::odleglosc(punkt p)
{
	return sqrt(std::pow(this->x - p.x, 2) + std::pow(this->y - p.y, 2));
}





void zad4() {
	
	punkt a,o,p;
	
	double odl1, odl2;
	odl1 = a.odleglosc(o);
	odl2 = a.odleglosc(o);
	if (odl1 == odl2)
	{
		std::cout << "punkty s¹ w tej samej odleg³osci:" << odl1;
	}
	if (odl1<odl2)
	{
		std::cout << "punkt o jest blizej:" << odl1;
	}
	else
	{
		std::cout << "punkt p jest blizej:" << odl2;
	}

}