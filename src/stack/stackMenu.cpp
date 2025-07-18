// src/stack/stackMenu.cpp
// Provides the implementation for the stack menu interface.

#include <iostream>
#include "stackMenu.h"
#include "StaticStack.h"
#include "DynamicStack.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Forward declarations for the menu handlers
void handleStaticStack();
void handleDynamicStack();

/**
 * @brief Displays the main menu for stack operations.
 *
 * This function provides options to choose between a static stack and a dynamic stack,
 * or to go back to the main menu. It handles user input and calls the appropriate handler.
 */
void showStackMenu() {
    int choice;
    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Stack", {"Static Stack", "Dynamic Stack", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 3);

        switch (choice) {
            case 1:
                handleStaticStack(); // User chose static stack
                break;
            case 2:
                handleDynamicStack(); // User chose dynamic stack
                break;
            case 3:
                return; // Exit to the previous menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

/**
 * @brief Handles operations for the static stack.
 *
 * This function provides a menu for all static stack operations, such as push, pop,
 * peek, and display. It creates a StaticStack object and performs operations on it
 * based on user input.
 */
void handleStaticStack() {
    StaticStack stack;
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Static Stack Menu", {"Push", "Pop", "Peek", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: { // Push operation
                value = InputUtils::getValidatedInput<int>("Enter value to push onto static stack: ");
                try {
                    stack.push(value);
                    std::cout << UIUtils::GREEN << "Pushed " << value << " onto the stack." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 2: { // Pop operation
                try {
                    value = stack.pop();
                    std::cout << UIUtils::GREEN << "Popped value: " << value << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: { // Peek operation
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: // Display operation
                stack.display();
                break;
            case 5:
                return; // Go back to the stack type selection menu
        }
        if (choice != 5) {
            UIUtils::waitForEnter(); // Pause to allow the user to see the output
        }
    } while (choice != 5);
}

/**
 * @brief Handles operations for the dynamic stack.
 *
 * This function provides a menu for all dynamic stack operations, such as push, pop,
 * peek, and display. It creates a DynamicStack object and performs operations on it
 * based on user input.
 */
void handleDynamicStack() {
    DynamicStack stack;
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Dynamic Stack Menu", {"Push", "Pop", "Peek", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: { // Push operation
                value = InputUtils::getValidatedInput<int>("Enter value to push onto dynamic stack: ");
                stack.push(value);
                std::cout << UIUtils::GREEN << "Pushed " << value << " onto the stack." << UIUtils::RESET << std::endl;
                break;
            }
            case 2: { // Pop operation
                try {
                    value = stack.pop();
                    std::cout << UIUtils::GREEN << "Popped value: " << value << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: { // Peek operation
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: // Display operation
                stack.display();
                break;
            case 5:
                return; // Go back to the stack type selection menu
        }
        if (choice != 5) {
            UIUtils::waitForEnter(); // Pause to allow the user to see the output
        }
    } while (choice != 5);
}