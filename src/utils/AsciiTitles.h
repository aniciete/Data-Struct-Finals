#ifndef ASCII_TITLES_H
#define ASCII_TITLES_H

#include <string>
#include <unordered_map>

// Namespace for managing ASCII art titles in menu displays
namespace AsciiTitles {
    // Returns ASCII art for a given menu title, or empty string if not found
    const std::string& getAsciiArt(const std::string& title);
}

#endif // ASCII_TITLES_H
