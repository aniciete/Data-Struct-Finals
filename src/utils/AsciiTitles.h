#ifndef ASCII_TITLES_H
#define ASCII_TITLES_H

#include <string>
#include <unordered_map>

/**
 * @brief Namespace for managing and retrieving ASCII art titles for menu displays.
 * 
 * This namespace provides a centralized way to handle ASCII art, making it easy
 * to display stylized titles in the console application.
 */
namespace AsciiTitles {
    /**
     * @brief Retrieves the ASCII art for a given menu title.
     * 
     * This function looks up the provided title in a map of predefined ASCII art strings.
     * If a matching title is found, a constant reference to the ASCII art is returned.
     * If the title is not found, a reference to an empty string is returned.
     * 
     * @param title The title of the menu to retrieve the ASCII art for.
     * @return A constant reference to the ASCII art string, or an empty string if not found.
     */
    const std::string& getAsciiArt(const std::string& title);
}

#endif // ASCII_TITLES_H