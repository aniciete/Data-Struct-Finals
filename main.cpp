#include <iostream>
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"

void showMainMenu();
void showStackMenu();
void showQueueMenu();
void showTreeMenu();
void showGraphMenu();
void showSortingMenu();

void handleStaticStack();
void handleDynamicStack();

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
                showQueueMenu();
                break;
            case 3:
                showTreeMenu();
                break;
            case 4:
                showGraphMenu();
                break;
            case 5:
                showSortingMenu();
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

void showQueueMenu() {
    int choice;
    StaticQueue staticQueue;
    DynamicQueue dynamicQueue;

    std::cout << "\n--- Queue Operations ---\n";
    std::cout << "1. Use Static Queue\n";
    std::cout << "2. Use Dynamic Queue\n";
    std::cout << "3. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        // Static Queue implementation
    } else if (choice == 2) {
        // Dynamic Queue implementation
    }
}

void showTreeMenu() {
    BinaryTree tree;
    int choice, value;

    do {
        std::cout << "\n--- Binary Tree Menu ---\n";
        std::cout << "1. Insert Node\n";
        std::cout << "2. Delete Node\n";
        std::cout << "3. Search Node\n";
        std::cout << "4. In-order Traversal\n";
        std::cout << "5. Pre-order Traversal\n";
        std::cout << "6. Post-order Traversal\n";
        std::cout << "7. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                tree.insertNode(value);
                break;
            case 2:
                std::cout << "Enter value to delete: ";
                std::cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (tree.searchNode(value)) {
                    std::cout << "Node found in the tree.\n";
                } else {
                    std::cout << "Node not found in the tree.\n";
                }
                break;
            case 4:
                tree.inOrderTraversal();
                break;
            case 5:
                tree.preOrderTraversal();
                break;
            case 6:
                tree.postOrderTraversal();
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void showGraphMenu() {
    Graph graph;
    int choice, v1, v2;

    do {
        std::cout << "\n--- Graph Menu ---\n";
        std::cout << "1. Add Vertex\n";
        std::cout << "2. Add Edge\n";
        std::cout << "3. Remove Vertex\n";
        std::cout << "4. Remove Edge\n";
        std::cout << "5. Display Graph\n";
        std::cout << "6. Traverse Graph (BFS)\n";
        std::cout << "7. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter vertex value: ";
                std::cin >> v1;
                graph.addVertex(v1);
                break;
            case 2:
                std::cout << "Enter first vertex: ";
                std::cin >> v1;
                std::cout << "Enter second vertex: ";
                std::cin >> v2;
                graph.addEdge(v1, v2);
                break;
            case 3:
                std::cout << "Enter vertex to remove: ";
                std::cin >> v1;
                graph.removeVertex(v1);
                break;
            case 4:
                std::cout << "Enter first vertex of edge to remove: ";
                std::cin >> v1;
                std::cout << "Enter second vertex of edge to remove: ";
                std::cin >> v2;
                graph.removeEdge(v1, v2);
                break;
            case 5:
                graph.display();
                break;
            case 6:
                std::cout << "Enter starting vertex for traversal: ";
                std::cin >> v1;
                graph.traverse(v1);
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void showSortingMenu() {
    std::cout << "Sorting algorithms to be implemented.\n";
}
