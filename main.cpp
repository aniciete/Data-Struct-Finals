#include <iostream>

// Include all the team's header files from their new locations
// The -Isrc flag in the Makefile allows us to use "module/file.h"
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"

void showMainMenu() {
    std::cout << "========================================\n";
    std::cout << "    DATA STRUCTURES & ALGORITHMS\n";
    std::cout << "         DEMONSTRATION PROGRAM\n";
    std::cout << "========================================\n\n";
    std::cout << "1. Stack Operations\n";
    std::cout << "2. Queue Operations\n";
    std::cout << "3. Tree Operations\n";
    std::cout << "4. Graph Operations\n";
    std::cout << "5. Sorting Algorithms\n";
    std::cout << "6. Exit Program\n\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                // To-Do: Implement Stack sub-menu
                std::cout << "Stack operations to be implemented.\n";
                break;
            case 2:
                // To-Do: Implement Queue sub-menu
                std::cout << "Queue operations to be implemented.\n";
                break;
            case 3:
                // To-Do: Implement Tree sub-menu
                std::cout << "Tree operations to be implemented.\n";
                break;
            case 4:
                // To-Do: Implement Graph sub-menu
                std::cout << "Graph operations to be implemented.\n";
                break;
            case 5:
                // To-Do: Implement Sorting sub-menu
                std::cout << "Sorting algorithms to be implemented.\n";
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