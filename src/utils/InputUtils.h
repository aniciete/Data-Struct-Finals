#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <vector>
#include <string>
#include <limits>

#include <iostream>
#include <sstream>

// Template function to get validated input with optional min/max range checking
template <typename T>
T getValidatedInput(const std::string& prompt, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
    T value;
    std::string line;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) {
            // This handles EOF or other fatal stream errors
            std::cout << "End of input reached or stream error. Exiting.\n";
            exit(0);
        }

        // Ignore empty lines, which are common in test files
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        // Check that the entire line was consumed by the extraction
        if (ss >> value && (ss >> std::ws).eof()) {
            if (value >= min && value <= max) {
                return value; // Success
            } else {
                std::cout << "Input out of range. Please enter a number between " << min << " and " << max << ".\n";
            }
        } else {
            // This handles non-numeric input or lines with extra garbage
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
}

// Utility functions for array input handling
int getArraySize();
std::vector<int> getCustomArray(int size);
void displayArray(const std::vector<int>& arr, const std::string& label);
int getArrayChoice();

#endif // INPUT_UTILS_H