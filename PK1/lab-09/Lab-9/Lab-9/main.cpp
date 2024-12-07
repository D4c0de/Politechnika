#include <fstream>
#include "zad.h"


int main() {
	std::ifstream fin("input.txt");
	zad1(&fin);

	return 0;
}