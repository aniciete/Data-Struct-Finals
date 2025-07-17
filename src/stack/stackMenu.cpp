#include <iostream>
#include "stackMenu.h"
#include "StaticStack.h"
#include "DynamicStack.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Forward declarations for handlers
void handleStaticStack();
void handleDynamicStack();

// Display the main stack menu and handle user choices
void showStackMenu() {
    int choice;
    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Stack Operations", {"Static Stack", "Dynamic Stack", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 3);

        switch (choice) {
            case 1:
                handleStaticStack();  // Show static stack operations
                break;
            case 2:
                handleDynamicStack(); // Show dynamic stack operations
                break;
            case 3:
                return;               // Go back to main menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Handle static stack operations menu
void handleStaticStack() {
    StaticStack stack;  // Create a static stack instance
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Static Stack Menu", {"Push", "Pop", "Peek", "Display", "Back to Stack Menu"});
        choice = getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: {
                // Push operation: Add element to stack
                value = getValidatedInput<int>("Enter value to push: ");
                try {
                    stack.push(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                // Pop operation: Remove and return top element
                try {
                    value = stack.pop();
                    std::cout << "Popped value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                // Peek operation: View top element without removing
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4:
                // Display all stack elements
                stack.display();
                break;
            case 5:
                // Go back to stack menu
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

// Handle dynamic stack operations menu
void handleDynamicStack() {
    DynamicStack stack;  // Create a dynamic stack instance
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Dynamic Stack Menu", {"Push", "Pop", "Peek", "Display", "Back to Stack Menu"});
        choice = getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: {
                // Push operation: Add element to stack
                value = getValidatedInput<int>("Enter value to push: ");
                stack.push(value);
                break;
            }
            case 2: {
                // Pop operation: Remove and return top element
                try {
                    value = stack.pop();
                    std::cout << "Popped value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                // Peek operation: View top element without removing
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4:
                // Display all stack elements
                stack.display();
                break;
            case 5:
                // Go back to stack menu
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
