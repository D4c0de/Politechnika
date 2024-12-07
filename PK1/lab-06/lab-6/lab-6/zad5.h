#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
struct id
{
	std::string name;
	std::string surname;
	int birthYear;
	static bool IsHigherName(id i1,id i2) {
		return i1.name > i2.name;
	}
	static bool IsHigherSurname(id i1,id i2) {
		return i1.surname > i2.surname;
	}
	static bool IsHigherYear(id i1,id i2) {
		return i1.birthYear > i2.birthYear;
	}
	id(std::string name, std::string surname, int birthYear) {
		this->name = name;
		this->surname = surname;
		this->birthYear = birthYear;
	};
};

std::vector<id>* fileInput(std::string fileName) {
	std::fstream file(fileName, std::ios::in);

	if (!file.good()) {
		std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
		return;
	}

	std::string imie, nazwisko;
	int rokUrodzenia;
	std::vector<id>* vec = new std::vector<id>;
	// Odczyt danych z pliku do wektorów
	while (file >> imie >> nazwisko >> rokUrodzenia) {
		vec->push_back(id(imie,nazwisko,rokUrodzenia));
	}
	
	file.close();
	return vec;
}
void fileOutput(std::string fileName, std::vector<id>& fileOutput) {
	
	std::fstream file(fileName, std::ios::out);

	if (!file.good()) {
		std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
		return;
	}

	for (size_t i = 0; i < fileOutput.size(); i++){
		file << fileOutput[i].name << fileOutput[i].surname << fileOutput[i].surname;
	}
	file.close();
}
void sort(int var,std::vector<id>* vec) {

	if (var==0)
	{
		std::sort(vec->begin(), vec->end(), id::IsHigherName);
	}
	else if (var==1)
	{
		std::sort(vec->begin(), vec->end(), id::IsHigherSurname);
	}
	else
	{
		std::sort(vec->begin(), vec->end(), id::IsHigherYear);
	}
}