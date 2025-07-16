#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"
#include "utils/InputUtils.h"

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
        choice = getValidatedInput<int>("", 1, 6);

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
        choice = getValidatedInput<int>("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                value = getValidatedInput<int>("Enter value to push: ");
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
        choice = getValidatedInput<int>("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                value = getValidatedInput<int>("Enter value to push: ");
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
    choice = getValidatedInput<int>("Enter your choice: ", 1, 3);

    if (choice == 1) {
        int staticChoice, value;
        do {
            std::cout << "\n--- Static Queue Menu ---\n";
            std::cout << "1. Enqueue\n";
            std::cout << "2. Dequeue\n";
            std::cout << "3. Front\n";
            std::cout << "4. Rear\n";
            std::cout << "5. Display\n";
            std::cout << "6. Back to Queue Menu\n";
            staticChoice = getValidatedInput<int>("Enter your choice: ", 1, 6);

            switch (staticChoice) {
                case 1:
                    value = getValidatedInput<int>("Enter value to enqueue: ");
                    staticQueue.enqueue(value);
                    break;
                case 2:
                    staticQueue.dequeue();
                    break;
                case 3:
                    value = staticQueue.front();
                    if (value != -1) {
                        std::cout << "Front value: " << value << std::endl;
                    }
                    break;
                case 4:
                    value = staticQueue.rear();
                    if (value != -1) {
                        std::cout << "Rear value: " << value << std::endl;
                    }
                    break;
                case 5:
                    staticQueue.display();
                    break;
                case 6:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (staticChoice != 6);
    } else if (choice == 2) {
        int dynamicChoice, value;
        do {
            std::cout << "\n--- Dynamic Queue Menu ---\n";
            std::cout << "1. Enqueue\n";
            std::cout << "2. Dequeue\n";
            std::cout << "3. Front\n";
            std::cout << "4. Rear\n";
            std::cout << "5. Display\n";
            std::cout << "6. Back to Queue Menu\n";
            dynamicChoice = getValidatedInput<int>("Enter your choice: ", 1, 6);

            switch (dynamicChoice) {
                case 1:
                    value = getValidatedInput<int>("Enter value to enqueue: ");
                    dynamicQueue.enqueue(value);
                    break;
                case 2:
                    dynamicQueue.dequeue();
                    break;
                case 3:
                    value = dynamicQueue.front();
                    if (value != -1) {
                        std::cout << "Front value: " << value << std::endl;
                    }
                    break;
                case 4:
                    value = dynamicQueue.rear();
                    if (value != -1) {
                        std::cout << "Rear value: " << value << std::endl;
                    }
                    break;
                case 5:
                    dynamicQueue.display();
                    break;
                case 6:
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (dynamicChoice != 6);
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
        choice = getValidatedInput<int>("Enter your choice: ", 1, 7);

        switch (choice) {
            case 1:
                value = getValidatedInput<int>("Enter value to insert: ");
                tree.insertNode(value);
                break;
            case 2:
                value = getValidatedInput<int>("Enter value to delete: ");
                tree.deleteNode(value);
                break;
            case 3:
                value = getValidatedInput<int>("Enter value to search: ");
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
        choice = getValidatedInput<int>("Enter your choice: ", 1, 7);

        switch (choice) {
            case 1:
                v1 = getValidatedInput<int>("Enter vertex value: ");
                graph.addVertex(v1);
                break;
            case 2:
                v1 = getValidatedInput<int>("Enter first vertex: ");
                v2 = getValidatedInput<int>("Enter second vertex: ");
                graph.addEdge(v1, v2);
                break;
            case 3:
                v1 = getValidatedInput<int>("Enter vertex to remove: ");
                graph.removeVertex(v1);
                break;
            case 4:
                v1 = getValidatedInput<int>("Enter first vertex of edge to remove: ");
                v2 = getValidatedInput<int>("Enter second vertex of edge to remove: ");
                graph.removeEdge(v1, v2);
                break;
            case 5:
                graph.display();
                break;
            case 6:
                v1 = getValidatedInput<int>("Enter starting vertex for traversal: ");
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
    int choice;

    do {
        std::cout << "\n--- Sorting Algorithms Menu ---\n";
        std::cout << "1. Bubble Sort\n";
        std::cout << "2. Merge Sort\n";
        std::cout << "3. Quick Sort\n";
        std::cout << "4. Back to Main Menu\n";
        choice = getValidatedInput<int>("Enter your choice: ", 1, 4);

        if (choice >= 1 && choice <= 3) {
            // Get array choice after algorithm selection
            int arrayChoice = getArrayChoice();
            std::vector<int> originalArray;
            
            // Build array based on user choice
            if (arrayChoice == 1) {
                // Use default array
                originalArray = {64, 34, 25, 12, 22, 11, 90};
            } else {
                // Get custom array from user
                int size = getArraySize();
                originalArray = getCustomArray(size);
            }
            
            // Display original array
            displayArray(originalArray, "Original array");
            
            // Create a copy for sorting to preserve original
            std::vector<int> sortingArray = originalArray;
            
            // Execute selected sorting algorithm
            switch (choice) {
                case 1:
                    bubbleSort(sortingArray);
                    break;
                case 2:
                    mergeSort(sortingArray.begin(), sortingArray.end());
                    break;
                case 3:
                    quickSort(sortingArray.begin(), sortingArray.end());
                    break;
            }
            
            // Display sorted array
            displayArray(sortingArray, "Sorted array");
            std::cout << std::endl;
            
        } else if (choice == 4) {
            return;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
