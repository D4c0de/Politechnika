<<<<<<< HEAD
#pragma once

void zad9(int* tab,int size) {
	sort(tab, size);
}
void sort(int* tab,int size){

	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (tab[j] > tab[j + 1]) {
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
=======
#pragma once

void zad9(int* tab,int size) {
	sort(tab, size);
}
void sort(int* tab,int size){

	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (tab[j] > tab[j + 1]) {
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
>>>>>>> 97603a3632f323dd0ad27a68f1bbdc7b27de0c0a
}