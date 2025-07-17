#ifndef UI_UTILS_H
#define UI_UTILS_H

#include <iostream>
#include <string>
#include <vector>

namespace UIUtils {

    // ANSI Color Codes
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";

    void printHeader(const std::string& title) {
        std::cout << BOLD << MAGENTA << "========================================\n";
        std::cout << "    " << title << "\n";
        std::cout << "========================================\n\n" << RESET;
    }

    void printMenu(const std::vector<std::string>& options) {
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << BOLD << CYAN << i + 1 << ". " << RESET << options[i] << "\n";
        }
        std::cout << "\nEnter your choice: ";
    }


    void printSubMenu(const std::string& title, const std::vector<std::string>& options) {
        std::cout << "\n--- " << BOLD << YELLOW << title << RESET << " ---\n";
        printMenu(options);
    }

}

#endif // UI_UTILS_H
