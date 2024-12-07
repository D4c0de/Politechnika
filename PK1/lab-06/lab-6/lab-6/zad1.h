#pragma once
#include <vector>
void fillRand(std::vector<int>* vec) {

	for (size_t i = 0; i < vec->size(); i++)
	{
		(*vec)[i] = std::rand() % 100 + 1;
	}
}