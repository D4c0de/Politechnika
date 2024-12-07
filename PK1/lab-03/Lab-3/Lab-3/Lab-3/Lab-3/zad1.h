#pragma once
#include <iostream>

void zad1() {
	
	
	/*
	int input;
	std::cin >> input;
	for (int i = 1; i <= input; i++)
	{
		std::cout << i << ' ';
	}
	int tmp = 1;
	std::cout << '\n';
	while (true)
	{
		if (tmp <= input)
		{
			std::cout << tmp << ' ';
			
			tmp++;
		}
		else
		{
			break;
		}
	}
	std::cout << '\n';
	tmp = 1;
	do
	{
		if (tmp <= input)
		{
			std::cout << tmp << ' ';
			tmp++;
		}
		else
		{
			break;
		}
	} while (true);
	std::cout << '\n';
	for (int i = input; i > 0; i--)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	tmp = input;
	while (true)
	{
		if (tmp > 0)
		{
			std::cout << tmp << ' ';
			tmp--;
		}
		else
		{
			break;
		}
	}
	std::cout << '\n';
	tmp = input;
	do
	{
		if (tmp > 0)
		{
			std::cout << tmp << ' ';
			tmp--;
		}
		else
		{
			break;
		}
	} while (true);
	std::cout << '\n';
	*/
	int start, stop, dzielnik;
	std::cin >>start>>  stop >> dzielnik;
	for (; start <= stop; start++)
	{
		if (start%dzielnik==0)
		{
			std::cout << start;
		}
	}
	int podstawa, wyk³adnik;

	std::cin >> podstawa >> wyk³adnik;
	int wynik = podstawa;
	for (int i = 1; i <= wyk³adnik; i++)
	{
		wynik *= podstawa;
	}
	std::cout << wynik;
}