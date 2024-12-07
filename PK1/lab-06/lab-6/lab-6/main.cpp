#include <vector>
#include "zad1.h"
#include "zad2.h"


int main() {

	std::vector<int> vec(255,0);
	fillRand(&vec);
	vectorCout(vec);

}