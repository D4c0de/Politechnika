#pragma once
#include <vector>

void vectorSelectionSort(std::vector<int>& vec) {

    for (int i = 0; i < vec.size()-1; ++i) {
        int indeksMin = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[indeksMin]) {
                indeksMin = j;
            }
        }
        if (indeksMin != i) {
            std::swap(vec[i], vec[indeksMin]);
        }
    }
}