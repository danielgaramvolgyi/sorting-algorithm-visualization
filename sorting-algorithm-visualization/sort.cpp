#include "sort.hpp"

void bubbleSort(std::vector<int>& v, SortLogger& logger) 
{
    logger.logInitialState(v);
    size_t size = v.size();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                logger.logAlgorithmStep(j, j+1);
                std::swap(v[j], v[j+1]);
            }
        }
    }
}

void insertionSort(std::vector<int>& v, SortLogger& logger)
{
    logger.logInitialState(v);
    size_t size = v.size();
    for (size_t i = 0; i < size; ++i) {
        int current = i;
        while (current > 0 && v[current - 1] > v[current]) {
            logger.logAlgorithmStep(current, current - 1);
            std::swap(v[current], v[current-1]);
            --current;
        }
    }
}
