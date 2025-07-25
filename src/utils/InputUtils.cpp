/**
 * @file InputUtils.cpp
 * @brief Implements utility functions for handling and validating user input.
 *
 * This file provides the definitions for functions that manage user input,
 * including getting validated numbers, characters, and custom arrays.
 */
#include "InputUtils.h"
#include "UIUtils.h"
#include <iostream>
#include <limits>
#include <vector>

// Namespace for input-related utility functions.
namespace InputUtils {

    // Prompts for and returns a valid array size from the user.
    int getArraySize() {
        // Uses a template function to get an integer between 1 and 100.
        return getValidatedInput<int>("Enter array size (1-100): ", 1, 100);
    }

    /**
     * @brief Prompts the user to enter the elements of a custom array.
     * 
     * This function takes a given size and prompts the user to enter each element
     * of the array one by one. It uses getValidatedInput for each element to ensure
     * valid integer input.
     * 
     * @param size The number of elements in the array.
     * @return A vector containing the user-defined array elements.
     */
    // Prompts the user to enter elements for a custom array of a given size.
    std::vector<int> getCustomArray(int size) {
        // Create a vector of the specified size.
        std::vector<int> arr(size);
        std::cout << "Enter " << size << " array elements:\n";
        
        // Loop to get each element from the user.
        for (int i = 0; i < size; i++) {
            // Get a validated integer for each element.
            arr[i] = getValidatedInput<int>("Element " + std::to_string(i + 1) + ": ");
        }
        
        return arr;
    }

    /**
     * @brief Displays the elements of an array with a given label.
     * 
     * This function iterates through the array and prints each element, separated by spaces.
     * A label is printed before the array elements for context.
     * 
     * @param arr The array to be displayed.
     * @param label A label to print before the array elements.
     */
    // Displays the elements of an integer vector with a given label.
    void displayArray(const std::vector<int>& arr, const std::string& label) {
        std::cout << label << ": ";
        // Iterate through the array and print each element.
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            // Add a space between elements, but not after the last one.
            if (i < arr.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prompts the user to choose between a default or custom array.
     * 
     * This function displays a submenu with options to use a default array, input a
     * custom array, or go back. It then gets a validated choice from the user.
     * 
     * @return An integer representing the user's choice.
     */
    int getArrayChoice() {
        UIUtils::printSubMenu("Array Options", {
            "Use default array {64, 34, 25, 12, 22, 11, 90}",
            "Input custom array",
            "← Back"
        });
        return getValidatedInput<int>("", 1, 3);
    }

    /**
     * @brief Gets a validated character input from a specific set of valid characters.
     * 
     * This function prompts the user for a single character input and validates it
     * against a provided list of valid characters. It will continue to prompt the
     * user until a valid character is entered.
     * 
     * @param prompt The message to display to the user.
     * @param validCharacters A vector of characters that are considered valid input.
     * @return The validated character.
     */
    // Gets a single character from the user, validated against a list of allowed characters.
    char getValidatedInput(const std::string& prompt, const std::vector<char>& validCharacters) {
        char value;
        std::string line;

        // Loop until a valid character is entered.
        while (true) {
            std::cout << prompt;
            // Read the entire line of input to handle extra characters.
            if (!std::getline(std::cin, line)) {
                std::cout << "End of input reached or stream error. Exiting.\n";
                exit(0); // Exit if input stream fails.
            }

            // Check if the input is a single character.
            if (line.length() == 1) {
                value = line[0];
                // Check if the character is in the list of valid characters.
                for (char c : validCharacters) {
                    if (value == c) {
                        return value; // Return the valid character.
                    }
                }
            }
            
            // If input is invalid, show an error and the list of valid characters.
            std::cout << "Invalid input. Please enter one of the following characters: ";
            for (size_t i = 0; i < validCharacters.size(); ++i) {
                std::cout << validCharacters[i] << (i < validCharacters.size() - 1 ? ", " : "");
            }
            std::cout << std::endl;
        }
    }

} // namespace InputUtils