#include "SortingAlgorithms.h"
#include <vector>

// Bubble sort: Simple sorting algorithm that repeatedly steps through the list
void SortingAlgorithms::bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        // Each pass bubbles the largest element to the end
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);  // Swap adjacent elements if out of order
            }
        }
    }
}


