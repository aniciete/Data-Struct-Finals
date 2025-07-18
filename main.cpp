/**
 * @file main.cpp
 * @brief Main entry point for the Data Structures and Algorithms final project.
 *
 * @details
 * **Academic Information:**
 * - **Course:** CCS0015L - Data Structures and Algorithms (Lab)
 * - **Institution:** Far Eastern University Institute of Technology
 * - **Schedule:** TB02 WED 10:00 - 12:50
 * - **Instructor:** Ronel F. Ramos, MIT
 * - **Submission Date:** July 18, 2025
 * - **Project Type:** Finals Project
 *
 * @authors
 * - **Aniciete:** Static Stack, Dynamic Stack, Main Program Architecture
 * - **Buising:** Static Queue, Dynamic Queue
 * - **Einstein:** Tree (Pre/Post/In Order Traversal)
 * - **Manaloto:** Graph (Adjacency List)
 * - **Manalo:** Sorting Algorithms (3 algorithms)
 */

// Include necessary standard libraries
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <chrono>

// Include header files for data structures
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"

// Include utility headers
#include "utils/InputUtils.h"
#include "utils/UIUtils.h"
#include "utils/AsciiTitles.h"

// Include menu headers for different data structures
#include "stack/stackMenu.h"
#include "queue/queueMenu.h"
#include "tree/treeMenu.h"
#include "graph/graphMenu.h"
#include "sorting/sortingMenu.h"

// Function prototypes
void showMainMenu();
void showSplashScreen();

// Main function: Entry point of the program
int main() {
    int choice;
    showSplashScreen(); // Display the splash screen at the start

    // Main loop to display the menu and handle user input
    do {
        showMainMenu(); // Show the main menu options
        // Get user input and validate it to be between 1 and 7
        choice = InputUtils::getValidatedInput<int>("", 1, 7);

        // Switch statement to handle the user's choice
        switch (choice) {
            case 1: showStackMenu(); break;   // Show stack operations menu
            case 2: showQueueMenu(); break;   // Show queue operations menu
            case 3: showTreeMenu(); break;    // Show tree operations menu
            case 4: showGraphMenu(); break;   // Show graph operations menu
            case 5: showSortingMenu(); break; // Show sorting algorithms menu
            case 6: {
                // Confirm if the user wants to exit
                char confirm = InputUtils::getValidatedInput("Are you sure you want to exit? (y/n): ", {'y', 'n'});
                if (confirm == 'y') {
                    std::cout << "Exiting program. Goodbye!\n";
                    return 0; // Exit the program
                }
                break;
            }
            default:
                // Handle invalid input
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n";
    } while (true); // Loop indefinitely until the user chooses to exit

    return 0; // Return 0 to indicate successful execution
}

// Function to display the main menu
void showMainMenu() {
    UIUtils::clearScreen(); // Clear the console screen
    UIUtils::printTitle("Main"); // Print the main menu title
    // Print the list of menu options
    UIUtils::printMenu({
        "Stack Operations",
        "Queue Operations",
        "Tree Operations",
        "Graph Operations",
        "Sorting Algorithms",
        "Exit Program",
    });
}

// Function to display the splash screen
void showSplashScreen() {
    UIUtils::clearScreen(); // Clear the console screen
    UIUtils::printTitle("Welcome"); // Print the welcome title
    UIUtils::waitForEnter(); // Wait for the user to press Enter
}