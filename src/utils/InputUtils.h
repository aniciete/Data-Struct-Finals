#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <vector>
#include <string>
#include <limits>

#include <iostream>

template <typename T>
T getValidatedInput(const std::string& prompt, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (value < min || value > max) {
            std::cout << "Input out of range. Please enter a number between " << min << " and " << max << ".\n";
            continue;
        }

        return value;
    }
}

int getArraySize();
std::vector<int> getCustomArray(int size);
void displayArray(const std::vector<int>& arr, const std::string& label);
int getArrayChoice();

#endif // INPUT_UTILS_H