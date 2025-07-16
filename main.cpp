#include <iostream>
#include <vector>
#include "SortingAlgorithms.h"

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // bubbleSort(arr);
    // mergeSort(arr, 0, arr.size() - 1);
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
