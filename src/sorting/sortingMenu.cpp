#include <iostream>
#include <vector>
#include <chrono>
#include "sortingMenu.h"
#include "SortingAlgorithms.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Forward declarations for local helpers
int getArrayChoice();
int getArraySize();
std::vector<int> getCustomArray(int size);
void displayArray(const std::vector<int>& arr, const std::string& label);

// Display the sorting algorithms menu and handle user choices
void showSortingMenu() {
    int choice;
    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Sorting Algorithms Menu", {"Bubble Sort", "Merge Sort", "Quick Sort", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 4);

        if (choice >= 1 && choice <= 3) {
            // Get array data from user (default or custom)
            int arrayChoice = getArrayChoice();
            std::vector<int> originalArray;
            
            if (arrayChoice == 1) {
                originalArray = {64, 34, 25, 12, 22, 11, 90};  // Default test array
            } else {
                int size = getArraySize();
                originalArray = getCustomArray(size);  // User-defined array
            }
            
            displayArray(originalArray, "Original array");
            
            std::vector<int> sortingArray = originalArray;  // Copy for sorting
            
            // Time the sorting operation
            auto start = std::chrono::high_resolution_clock::now();
            switch (choice) {
                case 1:
                    SortingAlgorithms::bubbleSort(sortingArray);
                    break;
                case 2:
                    SortingAlgorithms::mergeSort(sortingArray.begin(), sortingArray.end());
                    break;
                case 3:
                    SortingAlgorithms::quickSort(sortingArray.begin(), sortingArray.end());
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            displayArray(sortingArray, "Sorted array");
            std::cout << "Time taken: " << duration.count() << " microseconds\n";
            std::cout << std::endl;
            UIUtils::waitForEnter();
            
        } else if (choice == 4) {
            return;  // Go back to main menu
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Get user's choice for array source (default or custom)
int getArrayChoice() {
    UIUtils::printSubMenu("Choose Array Source", {"Use default array", "Enter custom array"});
    return getValidatedInput<int>("", 1, 2);
}

// Get the size of the custom array from user
int getArraySize() {
    return getValidatedInput<int>("Enter the number of elements: ", 1, 100); // Limit size for practicality
}

// Get custom array elements from user input
std::vector<int> getCustomArray(int size) {
    std::vector<int> arr;
    for (int i = 0; i < size; ++i) {
        arr.push_back(getValidatedInput<int>("Enter element " + std::to_string(i + 1) + ": "));
    }
    return arr;
}

// Display array contents with a descriptive label
void displayArray(const std::vector<int>& arr, const std::string& label) {
    std::cout << label << ": ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
