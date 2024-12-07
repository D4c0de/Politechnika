#pragma once
#include <iostream>
#include <vector>
#include <cmath>

double sredniaElementow(const std::vector<int>& a) {
	if (a.empty()) {
		// Sprawdzenie, czy wektor jest pusty, aby unikn¹æ dzielenia przez zero.
		std::cerr << "Wektor jest pusty." << std::endl;
		return 0.0; // Mo¿esz zwróciæ 0 lub inn¹ wartoœæ domyœln¹.
	}

	int suma = 0;
	for (int element : a) {
		suma += element;
	}

	// Oblicz œredni¹ dziel¹c sumê przez liczbê elementów.
	double srednia = static_cast<double>(suma) / a.size();

	return srednia;
}
int max(const std::vector<int>& a) {
	int maximum = a[0];
	for (size_t i = 1; i < a.size(); i++)
	{
		if (a[i] > maximum) {
			maximum = a[i];
		}
	}
	
	return maximum;
}
int min(const std::vector<int>& a) {
	int minimum = a[0];
	for (size_t i = 1; i < a.size(); i++)
	{
		if (a[i] < minimum) {
			minimum = a[i];
		}
	}

	return minimum;
}
double odchylenie(const std::vector<int>& data,double avg) {

	double avg2 = avg * avg;
	double sum=0;
	for (size_t i = 0; i < data.size(); i++)
	{
		sum+=(data[0]* data[0])- avg2;
	}
	sum /= data.size();
	return std::sqrt(sum);
}
void zad4() {
	std::vector<int>input;
	int temp;
	std::cin >> temp;
	input.push_back(temp);
	std::cin >> temp;
	input.push_back(temp);
	while (true)
	{
		std::cout<<"continue Y/N";
		char Q;
		std::cin >> Q;
		if (Q == 'N'||Q=='n')
		{
			break;
		}
		else if (Q == 'Y' || Q == 'y')
		{
			break;
		}
		else
		{
			continue;
		}
		std::cin >> temp;
		input.push_back(temp);
	}
	std::cout << input.size()<<'\n';
	std::cout << sredniaElementow(input) << '\n';
	std::cout << max(input) << '\n';
	std::cout << min(input) << '\n';
	std::cout << odchylenie(input, sredniaElementow(input)) << '\n';

}