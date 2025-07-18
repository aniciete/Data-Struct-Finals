#include "SortingAlgorithms.h"
#include <vector>

// Bubble sort: Simple sorting algorithm that repeatedly steps through the list.
void SortingAlgorithms::bubbleSort(std::vector<int>& arr) {
    int n = arr.size(); // Get the number of elements in the array.
    // Outer loop for the number of passes.
    for (int i = 0; i < n-1; i++) {
        // Inner loop for comparing adjacent elements.
        // Each pass bubbles the largest element to its correct position.
        for (int j = 0; j < n-i-1; j++) {
            // If the current element is greater than the next element, swap them.
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);  // Swap adjacent elements if they are in the wrong order.
            }
        }
    }
}


