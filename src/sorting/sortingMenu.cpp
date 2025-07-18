#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "sortingMenu.h"
#include "SortingAlgorithms.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Displays the menu for sorting algorithms and handles user interaction.
void showSortingMenu() {
    int choice;
    // Loop until the user chooses to go back to the main menu.
    do {
        UIUtils::clearScreen();
        // Print the sorting submenu with available algorithms.
        UIUtils::printSubMenu("Sort", {"Bubble Sort", "Merge Sort", "Quick Sort", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 4);

        // Process the user's choice if it's a sorting algorithm.
        if (choice >= 1 && choice <= 3) {
            // Ask the user to choose between a default or custom array.
            int arrayChoice = InputUtils::getArrayChoice();
            if (arrayChoice == 3) continue; // If user chooses 'Back', restart the loop.

            std::vector<int> originalArray;
            
            // Populate the array based on user's choice.
            if (arrayChoice == 1) {
                originalArray = {64, 34, 25, 12, 22, 11, 90};  // Use the default test array.
            } else {
                int size = InputUtils::getArraySize();
                originalArray = InputUtils::getCustomArray(size);  // Get a custom array from the user.
            }
            
            InputUtils::displayArray(originalArray, "Original array");
            
            std::vector<int> sortingArray = originalArray;  // Create a copy of the array for sorting.
            
            // Start the timer to measure sorting duration.
            auto start = std::chrono::high_resolution_clock::now();
            
            // Display a loading animation in a separate thread to improve user experience.
            std::thread loading_thread(UIUtils::showLoadingAnimation, 500);

            // Select and execute the chosen sorting algorithm.
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
            
            loading_thread.join(); // Wait for the loading animation to complete.
            
            // Stop the timer and calculate the duration.
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            // Display the sorted array and the time taken for the sorting operation.
            InputUtils::displayArray(sortingArray, "Sorted array");
            std::cout << "Time taken: " << duration.count() << " microseconds\n";
            std::cout << std::endl;
            UIUtils::waitForEnter();
            
        } else if (choice == 4) {
            return;  // Exit the function to go back to the main menu.
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}