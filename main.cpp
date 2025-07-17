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
        choice = getValidatedInput<int>("", 1, 6);

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
    UIUtils::printHeader("DATA STRUCTURES & ALGORITHMS\n         DEMONSTRATION PROGRAM");
    UIUtils::printMenu({
        "Stack Operations",
        "Queue Operations",
        "Tree Operations",
        "Graph Operations",
        "Sorting Algorithms",
        "Exit Program"
    });
}

