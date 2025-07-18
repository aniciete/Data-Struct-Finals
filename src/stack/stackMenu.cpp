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
        UIUtils::printSubMenu("Stack", {"Static Stack", "Dynamic Stack", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 3);

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
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// Handle static stack operations menu
void handleStaticStack() {
    StaticStack stack;
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Static Stack Menu", {"Push", "Pop", "Peek", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: {
                value = InputUtils::getValidatedInput<int>("Enter value to push onto static stack: ");
                try {
                    stack.push(value);
                    std::cout << UIUtils::GREEN << "Pushed " << value << " onto the stack." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 2: {
                try {
                    value = stack.pop();
                    std::cout << UIUtils::GREEN << "Popped value: " << value << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4:
                stack.display();
                break;
            case 5:
                return;
        }
        if (choice != 5) {
            UIUtils::waitForEnter(); // Added pause
        }
    } while (choice != 5);
}

// Handle dynamic stack operations menu
void handleDynamicStack() {
    DynamicStack stack;
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Dynamic Stack Menu", {"Push", "Pop", "Peek", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1: {
                value = InputUtils::getValidatedInput<int>("Enter value to push onto dynamic stack: ");
                stack.push(value);
                std::cout << UIUtils::GREEN << "Pushed " << value << " onto the stack." << UIUtils::RESET << std::endl;
                break;
            }
            case 2: {
                try {
                    value = stack.pop();
                    std::cout << UIUtils::GREEN << "Popped value: " << value << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    value = stack.peek();
                    std::cout << "Top value: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4:
                stack.display();
                break;
            case 5:
                return;
        }
        if (choice != 5) {
            UIUtils::waitForEnter(); // Added pause
        }
    } while (choice != 5);
}