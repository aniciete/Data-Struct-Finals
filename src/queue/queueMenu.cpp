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
    do {
        // No clearScreen() needed; printSubMenu handles it.
        UIUtils::printSubMenu("Queue", {"Static Queue", "Dynamic Queue", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 3);

        switch (choice) {
            case 1:
                handleStaticQueue();
                break;
            case 2:
                handleDynamicQueue();
                break;
            case 3:
                return;
        }
    } while (choice != 3);
}

// Handle static queue operations menu
void handleStaticQueue() {
    StaticQueue queue;
    int choice, value;

    do {
        // No clearScreen() needed; printSubMenu handles it.
        UIUtils::printSubMenu("Static Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = InputUtils::getValidatedInput<int>("Enter value to enqueue into static queue: ");
                try {
                    queue.enqueue(value);
                    std::cout << UIUtils::GREEN << "Enqueued " << value << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 2: {
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << UIUtils::GREEN << "Dequeued " << frontVal << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5:
                queue.display();
                break;
            case 6:
                return;
        }
        if (choice != 6) {
            UIUtils::waitForEnter();
        }
    } while (choice != 6);
}

// Handle dynamic queue operations menu
void handleDynamicQueue() {
    DynamicQueue queue;
    int choice, value;

    do {
        // No clearScreen() needed; printSubMenu handles it.
        UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = InputUtils::getValidatedInput<int>("Enter value to enqueue into dynamic queue: ");
                queue.enqueue(value);
                std::cout << UIUtils::GREEN << "Enqueued " << value << " successfully." << UIUtils::RESET << std::endl;
                break;
            }
            case 2: {
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << UIUtils::GREEN << "Dequeued " << frontVal << " successfully." << UIUtils::RESET << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << UIUtils::RED << "❌ Error: " << e.what() << UIUtils::RESET << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    value = queue.front();
                    std::cout << "Front element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                try {
                    value = queue.rear();
                    std::cout << "Rear element: " << value << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5:
                queue.display();
                break;
            case 6:
                return;
        }
        if (choice != 6) {
            UIUtils::waitForEnter();
        }
    } while (choice != 6);
}