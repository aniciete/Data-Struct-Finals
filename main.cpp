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

void showStackMenu(); // Forward declaration

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

void handleStaticStack() {
    StaticStack stack;
    int choice, value;

    do {
        std::cout << "\n--- Static Stack Menu ---\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Display\n";
        std::cout << "5. Back to Stack Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    std::cout << "Popped value: " << value << std::endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    std::cout << "Top value: " << value << std::endl;
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void handleDynamicStack() {
    DynamicStack stack;
    int choice, value;

    do {
        std::cout << "\n--- Dynamic Stack Menu ---\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Display\n";
        std::cout << "5. Back to Stack Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    std::cout << "Popped value: " << value << std::endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    std::cout << "Top value: " << value << std::endl;
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void showStackMenu() {
    int choice;
    std::cout << "\n--- Stack Operations ---\n";
    std::cout << "1. Use Static Stack\n";
    std::cout << "2. Use Dynamic Stack\n";
    std::cout << "3. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            handleStaticStack();
            break;
        case 2:
            handleDynamicStack();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Returning to Main Menu.\n";
    }
}

int main() {
    int choice;

    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                showStackMenu();
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