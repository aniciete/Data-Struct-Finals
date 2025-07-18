#ifndef UI_UTILS_H
#define UI_UTILS_H

#include <iostream>
#include <string>
#include <vector>

// Utility functions for user interface display and formatting
namespace UIUtils {

    // ANSI Color Codes for terminal text formatting
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";

    // Display a formatted header with title
    void printHeader(const std::string& title);

    // Display a numbered menu with options
    void printMenu(const std::vector<std::string>& options);

    // Displays a submenu with ASCII art title if available (see AsciiTitles.h)
    void printSubMenu(const std::string& title, const std::vector<std::string>& options);

    void clearScreen();     // Clear the terminal screen
    void waitForEnter();    // Wait for user to press Enter

}

#endif // UI_UTILS_H
