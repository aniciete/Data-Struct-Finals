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
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Queue", {"Static Queue", "Dynamic Queue", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 3);

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
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Static Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = getValidatedInput<int>("Enter value to enqueue: ");
                try {
                    queue.enqueue(value);
                    std::cout << "Enqueued " << value << " successfully.\n";
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << "Dequeued " << frontVal << " successfully." << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
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
            UIUtils::waitForEnter(); // Added pause
        }
    } while (choice != 6);
}

// Handle dynamic queue operations menu
void handleDynamicQueue() {
    DynamicQueue queue;
    int choice, value;

    do {
        UIUtils::clearScreen();
        UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = getValidatedInput<int>("Enter value to enqueue: ");
                queue.enqueue(value);
                std::cout << "Enqueued " << value << " successfully.\n";
                break;
            }
            case 2: {
                try {
                    int frontVal = queue.front();
                    queue.dequeue();
                    std::cout << "Dequeued " << frontVal << " successfully." << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
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
            UIUtils::waitForEnter(); // Added pause
        }
    } while (choice != 6);
}