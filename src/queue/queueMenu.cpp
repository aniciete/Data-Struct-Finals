#include <iostream>
#include "queueMenu.h"
#include "StaticQueue.h"
#include "DynamicQueue.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Forward declarations for handlers
void handleStaticQueue();
void handleDynamicQueue();

void showQueueMenu() {
    int choice;
    UIUtils::printSubMenu("Queue Operations", {"Static Queue", "Dynamic Queue", "Back to Main Menu"});
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
}

void handleStaticQueue() {
    StaticQueue queue;
    int choice, value;

    do {
        UIUtils::printSubMenu("Static Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = getValidatedInput<int>("Enter value to enqueue: ");
                try {
                    queue.enqueue(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                try {
                    queue.dequeue();
                    std::cout << "Dequeued successfully." << std::endl;
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
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void handleDynamicQueue() {
    DynamicQueue queue;
    int choice, value;

    do {
        UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
        choice = getValidatedInput<int>("", 1, 6);

        switch (choice) {
            case 1: {
                value = getValidatedInput<int>("Enter value to enqueue: ");
                try {
                    queue.enqueue(value);
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                try {
                    queue.dequeue();
                    std::cout << "Dequeued successfully." << std::endl;
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
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}
