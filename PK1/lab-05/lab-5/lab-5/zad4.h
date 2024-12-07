<<<<<<< HEAD
#pragma once
#include <iostream>
#include "zad2.h"
double distance(int dimention, int* pos1, int* pos2) {

	double distance = 0;

	for (int i = 0; i < dimention; i++) {
		distance += (pos1[i] - pos2[i]) * (pos1[i] - pos2[i]);
	}

	return sqrt(distance);
}

void zad4(int dest) {
	
	int* p1 = zad2(dest);
	int* p2 = zad2(dest);

	distance(dest, p1, p2);
=======
#pragma once
#include <iostream>
#include "zad2.h"
double distance(int dimention, int* pos1, int* pos2) {

	double distance = 0;

	for (int i = 0; i < dimention; i++) {
		distance += (pos1[i] - pos2[i]) * (pos1[i] - pos2[i]);
	}

	return sqrt(distance);
}

void zad4(int dest) {
	
	int* p1 = zad2(dest);
	int* p2 = zad2(dest);

	distance(dest, p1, p2);
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}