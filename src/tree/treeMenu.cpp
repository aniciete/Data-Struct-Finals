// This file implements the interactive menu for the Binary Search Tree (BST).
// It allows users to perform various operations such as inserting, deleting, searching,
// and traversing the tree. The menu is designed to be user-friendly, providing clear
// prompts and feedback for each action.

#include <iostream>
#include "treeMenu.h"
#include "BinaryTree.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

/**
 * @brief Displays the menu for binary search tree operations and handles user input.
 *
 * This function creates an instance of the BinaryTree and enters a loop to show the menu,
 * get user choices, and perform the corresponding actions until the user decides to exit.
 */
void showTreeMenu() {
    BinaryTree bst; // Create a BinaryTree instance
    int choice, value;

    do {
        // Display the submenu with all available tree operations
        UIUtils::printSubMenu("Tree", {
            "Insert Node", "Delete Node", "Search Node",
            "In-order Traversal", "Pre-order Traversal", "Post-order Traversal",
            "← Back"
        });
        choice = InputUtils::getValidatedInput<int>("", 1, 7);

        switch (choice) {
            case 1: // Insert a new node
                value = InputUtils::getValidatedInput<int>("Enter value to insert into BST: ");
                bst.insertNode(value);
                std::cout << UIUtils::GREEN << "Value inserted successfully." << UIUtils::RESET << std::endl;
                UIUtils::waitForEnter();
                break;
            case 2: // Delete a node
                value = InputUtils::getValidatedInput<int>("Enter value to delete from BST: ");
                bst.deleteNode(value);
                UIUtils::waitForEnter();
                break;
            case 3: // Search for a node
                value = InputUtils::getValidatedInput<int>("Enter value to search in BST: ");
                if (bst.searchNode(value)) {
                    std::cout << UIUtils::GREEN << "Value found in the tree." << UIUtils::RESET << std::endl;
                } else {
                    std::cout << UIUtils::RED << "Value not found in the tree." << UIUtils::RESET << std::endl;
                }
                UIUtils::waitForEnter();
                break;
            case 4: // In-order traversal
                std::cout << "In-order traversal: ";
                bst.inOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 5: // Pre-order traversal
                std::cout << "Pre-order traversal: ";
                bst.preOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 6: // Post-order traversal
                std::cout << "Post-order traversal: ";
                bst.postOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 7: // Exit the menu
                return; // Go back to the main menu
            default:
                // This case should not be reached due to input validation, but it's here as a safeguard
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}