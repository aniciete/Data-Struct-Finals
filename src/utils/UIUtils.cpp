/**
 * @file UIUtils.cpp
 * @brief Implements utility functions for creating and managing the user interface.
 *
 * This file contains the definitions for functions that handle UI elements like
 * titles, menus, screen clearing, and animations.
 */
#include "UIUtils.h"
#include "AsciiTitles.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <sstream>
#include <thread>

// Namespace for UI-related utility functions.
namespace UIUtils {

    // Displays a bordered ASCII art title.
    void printTitle(const std::string& titleKey) {
        // Retrieve the ASCII art string using the provided key.
        const std::string& ascii = AsciiTitles::getAsciiArt(titleKey);
        if (!ascii.empty()) {
            // Use a fixed width for the border for consistent alignment.
            const size_t fixedWidth = 150;
            std::string border(fixedWidth, '=');

            // Print the top border, the ASCII art, and the bottom border.
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
    // Pauses execution until the user presses the Enter key.
    void waitForEnter() {
        std::cout << "\nPress Enter to continue...";
        // Clear the input buffer to ignore any leftover characters.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // If the buffer was already empty, wait for a new character.
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
    // Displays a simple loading animation for a given duration.
    void showLoadingAnimation(int duration_ms) {
        // Spinner characters to create the animation effect.
        const char* spinner = "|/-\\";
        const int spin_delay_ms = 100; // Delay between each frame.
        const int num_spins = duration_ms / spin_delay_ms;
        
        std::cout << "\nSorting... ";
        // Loop to display the spinner animation.
        for (int i = 0; i < num_spins; ++i) {
            // Cycle through the spinner characters.
            std::cout << spinner[i % 4] << "\b" << std::flush;
            // Pause briefly to create the animation effect.
            std::this_thread::sleep_for(std::chrono::milliseconds(spin_delay_ms));
        }
        // Erase the final spinner character.
        std::cout << " \b";
    }

} // namespace UIUtils