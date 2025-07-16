#include "InputUtils.h"
#include <iostream>
#include <limits>

int getArraySize() {
    return getValidatedInput<int>("Enter array size (1-100): ", 1, 100);
}

std::vector<int> getCustomArray(int size) {
    std::vector<int> arr(size);
    std::cout << "Enter " << size << " array elements:\n";
    
    for (int i = 0; i < size; i++) {
        arr[i] = getValidatedInput<int>("Element " + std::to_string(i + 1) + ": ");
    }
    
    return arr;
}

void displayArray(const std::vector<int>& arr, const std::string& label) {
    std::cout << label << ": ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int getArrayChoice() {
    std::cout << "\n--- Array Options ---\n";
    std::cout << "1. Use default array {64, 34, 25, 12, 22, 11, 90}\n";
    std::cout << "2. Input custom array\n";
    return getValidatedInput<int>("Enter your choice: ", 1, 2);
}