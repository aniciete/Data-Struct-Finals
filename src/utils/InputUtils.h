#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Namespace for handling user input with validation.
 * 
 * This namespace provides a set of utility functions for getting validated
 * input from the user, ensuring that the input is of the correct type and
 * within a specified range.
 */
namespace InputUtils {

    /**
     * @brief Template function to get validated input from the user.
     * 
     * This function prompts the user for input and validates it against a specified
     * type and an optional range. It will continue to prompt the user until valid
     * input is received.
     * 
     * @tparam T The data type of the input to be validated.
     * @param prompt The message to display to the user.
     * @param min The minimum allowed value (inclusive).
     * @param max The maximum allowed value (inclusive).
     * @return The validated input value.
     */
    template <typename T>
    T getValidatedInput(const std::string& prompt, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
        T value;
        std::string line;

        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, line)) {
                // Handle EOF or other fatal stream errors
                std::cout << "End of input reached or stream error. Exiting.\n";
                exit(0);
            }

            // Ignore empty lines, which can occur in test files or with user input
            if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
                continue;
            }

            std::stringstream ss(line);
            // Ensure the entire line is consumed by the extraction
            if (ss >> value && (ss >> std::ws).eof()) {
                if (value >= min && value <= max) {
                    return value; // Success
                } else {
                    std::cout << "Input out of range. Please enter a number between " << min << " and " << max << ".\n";
                }
            } else {
                // Handle non-numeric input or lines with extra characters
                std::cout << "Invalid input. Please enter a valid number.\n";
            }
        }
    }

    /**
     * @brief Gets a validated character input from a specific set of valid characters.
     * 
     * @param prompt The message to display to the user.
     * @param validCharacters A vector of characters that are considered valid input.
     * @return The validated character.
     */
    char getValidatedInput(const std::string& prompt, const std::vector<char>& validCharacters);

    /**
     * @brief Prompts the user to enter the size of an array.
     * 
     * @return The size of the array, validated to be between 1 and 100.
     */
    int getArraySize();

    /**
     * @brief Prompts the user to enter the elements of a custom array.
     * 
     * @param size The number of elements in the array.
     * @return A vector containing the user-defined array elements.
     */
    std::vector<int> getCustomArray(int size);

    /**
     * @brief Displays the elements of an array with a given label.
     * 
     * @param arr The array to be displayed.
     * @param label A label to print before the array elements.
     */
    void displayArray(const std::vector<int>& arr, const std::string& label);

    /**
     * @brief Prompts the user to choose between a default or custom array.
     * 
     * @return An integer representing the user's choice (1 for default, 2 for custom, 3 to go back).
     */
    int getArrayChoice();

} // namespace InputUtils

#endif // INPUT_UTILS_H