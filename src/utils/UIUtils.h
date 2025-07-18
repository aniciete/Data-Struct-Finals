/**
 * @file UIUtils.h
 * @brief Declares utility functions for creating and managing the user interface.
 *
 * This header provides declarations for functions that handle UI elements,
 * including printing formatted titles, menus, and headers, as well as screen
 * clearing and animations. It also defines ANSI color codes for styling text.
 */
#ifndef UI_UTILS_H
#define UI_UTILS_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Namespace for utility functions related to the user interface.
 * 
 * This namespace provides functions for displaying and formatting UI elements
 * such as menus, titles, and headers, as well as handling screen clearing
 * and animations.
 */
namespace UIUtils {

    // ANSI Color Codes for formatting terminal text.
    const std::string RESET   = "\033[0m";
    const std::string BOLD    = "\033[1m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";

    /**
     * @brief Displays a formatted header with a title.
     * @param title The title to be displayed in the header.
     */
    void printHeader(const std::string& title);

    /**
     * @brief Displays a numbered menu with a list of options.
     * @param options A vector of strings representing the menu options.
     */
    void printMenu(const std::vector<std::string>& options);

    /**
     * @brief Displays a submenu, which includes clearing the screen, printing a title, and a menu.
     * @param title The title of the submenu, used to fetch ASCII art.
     * @param options A vector of strings for the menu options.
     */
    void printSubMenu(const std::string& title, const std::vector<std::string>& options);

    /**
     * @brief Displays a standalone, bordered ASCII art title.
     * @param titleKey The key to look up the ASCII art in the AsciiTitles map.
     */
    void printTitle(const std::string& titleKey);

    /**
     * @brief Clears the terminal screen.
     */
    void clearScreen();

    /**
     * @brief Pauses execution and waits for the user to press the Enter key.
     */
    void waitForEnter();

    /**
     * @brief Displays a simple loading animation for a specified duration.
     * @param duration_ms The total duration of the animation in milliseconds.
     */
    void showLoadingAnimation(int duration_ms);

} // namespace UIUtils

#endif // UI_UTILS_H