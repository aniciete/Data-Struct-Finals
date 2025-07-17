#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <chrono>
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"
#include "utils/InputUtils.h"
#include "utils/UIUtils.h"
#include "stack/stackMenu.h"
#include "queue/queueMenu.h"

void showMainMenu();


void showTreeMenu();
void showGraphMenu();
void showSortingMenu();





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
    UIUtils::printHeader("DATA STRUCTURES & ALGORITHMS\n         DEMONSTRATION PROGRAM");
    UIUtils::printMenu({
        "Stack Operations",
        "Queue Operations",
        "Tree Operations",
        "Graph Operations",
        "Sorting Algorithms",
        "Exit Program"
    });
}







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
            UIUtils::printSubMenu("Dynamic Queue Menu", {"Enqueue", "Dequeue", "Front", "Rear", "Display", "Back to Queue Menu"});
            dynamicChoice = getValidatedInput<int>("", 1, 6);

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
        UIUtils::printSubMenu("Binary Tree Menu", {"Insert Node", "Delete Node", "Search Node", "In-order Traversal", "Pre-order Traversal", "Post-order Traversal", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 7);

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
        UIUtils::printSubMenu("Graph Menu", {"Add Vertex", "Add Edge", "Remove Vertex", "Remove Edge", "Display Graph", "Traverse Graph (BFS)", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 7);

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
        UIUtils::printSubMenu("Sorting Algorithms Menu", {"Bubble Sort", "Merge Sort", "Quick Sort", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 4);

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
            
            // Execute selected sorting algorithm and measure performance
            auto start = std::chrono::high_resolution_clock::now();
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
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            // Display sorted array
            displayArray(sortingArray, "Sorted array");
            std::cout << "Time taken: " << duration.count() << " microseconds\n";
            std::cout << std::endl;
            
        } else if (choice == 4) {
            return;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}
