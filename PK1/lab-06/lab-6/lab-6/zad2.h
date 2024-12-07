#pragma once
#include <vector>
#include <iostream>
void vectorCout(std::vector<int>& vec) {

	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i]<<" ";
	}
}