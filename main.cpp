/**
 * @file main.cpp
 * @brief Main entry point for the Data Structures and Algorithms demonstration program.
 *
 * @details
 *   
 *   Far Eastern University Institute of Technology
 *     
 *   Course: CCS0015L
 *   Description: Data Structures and Algorithms (Lab)
 *   Professor: Ronel F. Ramos, MIT
 *
 *   Project Type: Finals Project
 *   Programming Language: C++
 *
 * @authors
 *   - Aniciete: Static Stack, Dynamic Stack, Main Program Architecture
 *   - Buising: Static Queue, Dynamic Queue
 *   - Einstein: Tree (Pre/Post/In Order Traversal)
 *   - Manaloto: Graph (Adjacency List)
 *   - Manalo: Sorting Algorithms (3 algorithms)
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <chrono>
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"
#include "utils/InputUtils.h"
#include "utils/UIUtils.h"
#include "utils/TestRunner.h"
#include "stack/stackMenu.h"
#include "queue/queueMenu.h"
#include "tree/treeMenu.h"
#include "graph/graphMenu.h"
#include "sorting/sortingMenu.h"

// Function declaration for main menu display
void showMainMenu();

// Main program entry point
int main() {
    int choice;

    do {
        showMainMenu();
        // Corrected validation range from 8 to 7
        choice = getValidatedInput<int>("", 1, 7);

        // Handle user's menu choice
        switch (choice) {
            case 1:
                showStackMenu();    // Stack operations
                break;
            case 2:
                showQueueMenu();    // Queue operations
                break;
            case 3:
                showTreeMenu();     // Tree operations
                break;
            case 4:
                showGraphMenu();    // Graph operations
                break;
            case 5:
                showSortingMenu();  // Sorting algorithms
                break;
            case 6:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            // Corrected case from 8 to 7 to match the menu
            case 7: {
                TestRunner runner("test.txt");
                runner.runTests();
                UIUtils::waitForEnter(); // Added pause to see test results
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n";
    } while (choice != 6);

    return 0;
}

// Display the main menu with program title and options
void showMainMenu() {
    UIUtils::clearScreen();
    UIUtils::printHeader("DATA STRUCTURES & ALGORITHMS\n         DEMONSTRATION PROGRAM");
    UIUtils::printMenu({
        "Stack Operations",
        "Queue Operations",
        "Tree Operations",
        "Graph Operations",
        "Sorting Algorithms",
        "Exit Program",
        "Run Automated Tests"
    });
}