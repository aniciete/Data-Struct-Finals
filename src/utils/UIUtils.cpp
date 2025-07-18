#include "UIUtils.h"
#include "AsciiTitles.h"
#include <iostream>
#include <limits> // Required for std::numeric_limits

namespace UIUtils {

// Clear the terminal screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Windows command
#else
    // ANSI escape code to clear screen on Unix/Linux/Mac
    std::cout << "\033[2J\033[1;1H";
#endif
}

// Wait for user to press Enter before continuing
void waitForEnter() {
    // This function is now enabled to allow users to see output
    std::cout << "\nPress Enter to continue...";
    // Clear any leftover characters in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Display a submenu with ASCII art title or fallback formatting
void printSubMenu(const std::string& title, const std::vector<std::string>& options) {
    std::string ascii = AsciiTitles::getAsciiArt(title);
    if (!ascii.empty()) {
        std::cout << "\n" << ascii << "\n";  // Use ASCII art if available
    } else {
        std::cout << "\n--- " << BOLD << YELLOW << title << RESET << " ---\n";  // Fallback formatting
    }
    printMenu(options);
}

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

} // namespace UIUtils