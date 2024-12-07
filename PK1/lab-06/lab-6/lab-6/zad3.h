#pragma once
#include <vector>
int foundMin(std::vector<int>& vec) {

	int min = vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
		}
	}
	return min;
}
int foundMax(std::vector<int>& vec) {

	int max = vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}
	return max;
}