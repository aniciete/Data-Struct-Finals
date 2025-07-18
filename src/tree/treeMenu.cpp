#include <iostream>
#include "treeMenu.h"
#include "BinaryTree.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Display the binary search tree menu and handle user choices
void showTreeMenu() {
    BinaryTree bst;  // Create a binary search tree instance
    int choice, value;

    do {
        UIUtils::clearScreen();
        // CORRECTED: Changed title to "Tree" to match the ASCII art key
        UIUtils::printSubMenu("Tree", {"Insert Node", "Delete Node", "Search Node", "In-order Traversal", "Pre-order Traversal", "Post-order Traversal", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 7); // Adjusted range

        switch (choice) {
            case 1:
                value = getValidatedInput<int>("Enter value to insert: ");
                bst.insertNode(value);
                UIUtils::waitForEnter();
                break;
            case 2:
                value = getValidatedInput<int>("Enter value to delete: ");
                bst.deleteNode(value);
                UIUtils::waitForEnter();
                break;
            case 3:
                value = getValidatedInput<int>("Enter value to search: ");
                if (bst.searchNode(value)) {
                    std::cout << "Value found in the tree.\n";
                } else {
                    std::cout << "Value not found in the tree.\n";
                }
                UIUtils::waitForEnter();
                break;
            case 4:
                std::cout << "In-order traversal: ";
                bst.inOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 5: // New case for Pre-order
                std::cout << "Pre-order traversal: ";
                bst.preOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 6: // New case for Post-order
                std::cout << "Post-order traversal: ";
                bst.postOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 7:
                return; // Back to main menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7); // Adjusted loop condition
}