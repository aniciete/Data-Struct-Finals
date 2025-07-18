#include <iostream>
#include "queueMenu.h"
#include "StaticQueue.h"
#include "DynamicQueue.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

/**
 * @brief Forward declarations for menu handler functions.
 *
 * These declarations are necessary because the functions are defined later in the file
 * but are called by `showQueueMenu`.
 */
void handleStaticQueue();
void handleDynamicQueue();

/**
 * @brief Displays the main queue menu and handles user choices.
 *
 * This function presents a menu with options for "Static Queue", "Dynamic Queue",
 * and "Back". It repeatedly prompts the user for a choice until they decide to go back.
 * Based on the choice, it calls the corresponding handler function.
 */
void showQueueMenu() {
    int choice;
    do {
        // The printSubMenu function handles clearing the screen.
        UIUtils::printSubMenu("Queue", {"Static Queue", "Dynamic Queue", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 3);

        switch (choice) {
            case 1:
                handleStaticQueue(); // User chose Static Queue
                break;
            case 2:
                handleDynamicQueue(); // User chose Dynamic Queue
                break;
            case 3:
                return; // Exit the menu
        }
    } while (choice != 3);
}

/**
 * @brief Handles the menu for static queue operations.
 *
 * This function creates a `StaticQueue` instance and provides a menu for operations
 * like enqueue, dequeue, front, rear, and display. It includes error handling
 * for operations that can fail (e.g., dequeue from an empty queue).
 */
void handleStaticQueue() {
    StaticQueue queue;
    int choice, value;

    do {
        UIUtils::printSubMenu("Static Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: { // Enqueue
                value = InputUtils::getValidatedInput<int>("Enter value to enqueue into static queue: ");
                try {
                    queue.enqueue(value);
                    std::cout << UIUtils::GREEN << "Enqueued " << value << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 2: { // Dequeue
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << UIUtils::GREEN << "Dequeued " << frontVal << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: { // Front
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: { // Rear
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5: // Display
                queue.display();
                break;
            case 6: // Back
                return;
        }
        if (choice != 6) {
            UIUtils::waitForEnter(); // Pause for user to see the output
        }
    } while (choice != 6);
}

/**
 * @brief Handles the menu for dynamic queue operations.
 *
 * This function creates a `DynamicQueue` instance and provides a menu for
 * operations like enqueue, dequeue, front, rear, and display. It includes
 * error handling for operations that might fail.
 */
void handleDynamicQueue() {
    DynamicQueue queue;
    int choice, value;

    do {
        UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: { // Enqueue
                value = InputUtils::getValidatedInput<int>("Enter value to enqueue into dynamic queue: ");
                queue.enqueue(value);
                std::cout << UIUtils::GREEN << "Enqueued " << value << " successfully." << UIUtils::RESET << std::endl;
                break;
            }
            case 2: { // Dequeue
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << UIUtils::GREEN << "Dequeued " << frontVal << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: { // Front
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: { // Rear
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5: // Display
                queue.display();
                break;
            case 6: // Back
                return;
        }
        if (choice != 6) {
            UIUtils::waitForEnter(); // Pause for user to see the output
        }
    } while (choice != 6);
}