<<<<<<< HEAD
#pragma once
#include <iostream>

void FillRand(int* tab,int size) {
	for (int i = 0; i < size; i++) {
		tab[i] = rand() % 100;
	}
}

int* zad2(int size) {
	int* tab = new int[size];
	FillRand(tab,size);
	return tab;
=======
#pragma once
#include <iostream>

void FillRand(int* tab,int size) {
	for (int i = 0; i < size; i++) {
		tab[i] = rand() % 100;
	}
}

int* zad2(int size) {
	int* tab = new int[size];
	FillRand(tab,size);
	return tab;
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}