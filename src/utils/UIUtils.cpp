#include "UIUtils.h"
#include "AsciiTitles.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <sstream>
#include <thread>

namespace UIUtils {

    /**
     * @brief Displays a standalone, bordered ASCII art title.
     * 
     * This function retrieves ASCII art using a key and displays it with a
     * decorative border. A fixed width is used for the border to ensure
     * consistent alignment in the terminal.
     * 
     * @param titleKey The key to look up the ASCII art in the AsciiTitles map.
     */
    void printTitle(const std::string& titleKey) {
        const std::string& ascii = AsciiTitles::getAsciiArt(titleKey);
        if (!ascii.empty()) {
            // A fixed width is used for all borders to ensure consistent UI alignment.
            const size_t fixedWidth = 150;
            std::string border(fixedWidth, '=');

            std::cout << MAGENTA << border << RESET << "\n";
            std::cout << ascii << "\n";
            std::cout << MAGENTA << border << RESET << "\n";
        }
    }

    /**
     * @brief Displays a submenu, which includes clearing the screen, printing a title, and a menu.
     * @param title The title of the submenu, used to fetch ASCII art.
     * @param options A vector of strings for the menu options.
     */
    void printSubMenu(const std::string& title, const std::vector<std::string>& options) {
        clearScreen();
        printTitle(title);
        printMenu(options);
    }

    /**
     * @brief Clears the terminal screen.
     * 
     * This function uses conditional compilation to support both Windows and Unix-like systems.
     * For Windows, it uses the "cls" command. For other systems, it uses ANSI escape codes.
     */
    void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        // ANSI escape code to clear screen and move cursor to top-left
        std::cout << "\033[2J\033[1;1H";
    #endif
    }

    /**
     * @brief Pauses execution and waits for the user to press the Enter key.
     * 
     * This function is used to hold the screen after an operation is complete,
     * allowing the user to see the output before returning to a menu.
     * It handles potential leftover newline characters in the input buffer.
     */
    void waitForEnter() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // This check is necessary to handle cases where the input buffer was already
        // empty, which can happen after a non-getline read.
        if (std::cin.gcount() == 0) {
            std::cin.get();
        }
    }

    /**
     * @brief Displays a formatted header with a title.
     * @param title The title to be displayed in the header.
     */
    void printHeader(const std::string& title) {
        std::cout << BOLD << MAGENTA << "========================================\n";
        std::cout << "    " << title << "\n";
        std::cout << "========================================\n\n" << RESET;
    }

    /**
     * @brief Displays a numbered menu with a list of options.
     * @param options A vector of strings representing the menu options.
     */
    void printMenu(const std::vector<std::string>& options) {
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << BOLD << CYAN << i + 1 << ". " << RESET << options[i] << "\n";
        }
        std::cout << "\nEnter your choice: ";
    }

    /**
     * @brief Displays a simple loading animation for a specified duration.
     * 
     * This function shows a spinning cursor animation to indicate that an
     * operation is in progress.
     * 
     * @param duration_ms The total duration of the animation in milliseconds.
     */
    void showLoadingAnimation(int duration_ms) {
        const char* spinner = "|/-\\";
        const int spin_delay_ms = 100;
        const int num_spins = duration_ms / spin_delay_ms;
        
        std::cout << "\nSorting... ";
        for (int i = 0; i < num_spins; ++i) {
            std::cout << spinner[i % 4] << "\b" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(spin_delay_ms));
        }
        std::cout << " \b"; // Erase the spinner character
    }

} // namespace UIUtils