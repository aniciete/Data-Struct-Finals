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
        UIUtils::printSubMenu("Binary Search Tree Menu", {"Insert Node", "Delete Node", "Search Node", "In-order Traversal", "Back to Main Menu"});
        choice = getValidatedInput<int>("", 1, 5);

        switch (choice) {
            case 1:
                // Insert operation: Add a new node to the tree
                value = getValidatedInput<int>("Enter value to insert: ");
                bst.insertNode(value);
                UIUtils::waitForEnter();
                break;
            case 2:
                // Delete operation: Remove a node from the tree
                value = getValidatedInput<int>("Enter value to delete: ");
                bst.deleteNode(value);
                UIUtils::waitForEnter();
                break;
            case 3:
                // Search operation: Look for a value in the tree
                value = getValidatedInput<int>("Enter value to search: ");
                if (bst.searchNode(value)) {
                    std::cout << "Value found in the tree.\n";
                } else {
                    std::cout << "Value not found in the tree.\n";
                }
                UIUtils::waitForEnter();
                break;
            case 4:
                // Traversal operation: Display tree in sorted order
                std::cout << "In-order traversal: ";
                bst.inOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 5:
                // Go back to main menu
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
