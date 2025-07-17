#include <iostream>
#include "queueMenu.h"
#include "StaticQueue.h"
#include "DynamicQueue.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Forward declarations for handlers
void handleStaticQueue();
void handleDynamicQueue();

// Display the main queue menu and handle user choices
void showQueueMenu() {
    int choice;
    UIUtils::clearScreen();
    UIUtils::printSubMenu("Queue Operations", {"Static Queue", "Dynamic Queue", "Back to Main Menu"});
    choice = getValidatedInput<int>("", 1, 3);

    switch (choice) {
        case 1:
            handleStaticQueue();  // Show static queue operations
            break;
        case 2:
            handleDynamicQueue(); // Show dynamic queue operations
            break;
        case 3:
            return;               // Go back to main menu
    }
}

// Handle static queue operations menu
void handleStaticQueue() {
    StaticQueue queue;  // Create a static queue instance
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Static Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                // Enqueue operation: Add element to rear of queue
                value = getValidatedInput<int>("Enter value to enqueue: ");
                try {
                    queue.enqueue(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                // Dequeue operation: Remove element from front of queue
                try {
                    queue.dequeue();
                    std::cout << "Dequeued successfully." << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                // Front operation: View front element without removing
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                // Rear operation: View rear element without removing
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5:
                // Display all queue elements
                queue.display();
                break;
            case 6:
                // Go back to queue menu
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

// Handle dynamic queue operations menu
void handleDynamicQueue() {
    DynamicQueue queue;  // Create a dynamic queue instance
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                // Enqueue operation: Add element to rear of queue
                value = getValidatedInput<int>("Enter value to enqueue: ");
                try {
                    queue.enqueue(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                // Dequeue operation: Remove element from front of queue
                try {
                    queue.dequeue();
                    std::cout << "Dequeued successfully." << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                // Front operation: View front element without removing
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                // Rear operation: View rear element without removing
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5:
                // Display all queue elements
                queue.display();
                break;
            case 6:
                // Go back to queue menu
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
