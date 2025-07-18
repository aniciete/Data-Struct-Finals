#include <iostream>
#include <vector>
#include <chrono>
#include "sortingMenu.h"
#include "SortingAlgorithms.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Display the sorting algorithms menu and handle user choices
void showSortingMenu() {
    int choice;
    do {
        UIUtils::clearScreen();
        // CORRECTED: Changed title to "Sort" to match the ASCII art key
        UIUtils::printSubMenu("Sort", {"Bubble Sort", "Merge Sort", "Quick Sort", "Back to Main Menu"});
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