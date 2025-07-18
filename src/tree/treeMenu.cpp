#include <iostream>
#include "treeMenu.h"
#include "BinaryTree.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Display the binary search tree menu and handle user choices
void showTreeMenu() {
    BinaryTree bst;
    int choice, value;

    do {
        // No clearScreen() needed; printSubMenu handles it.
        UIUtils::printSubMenu("Tree", {"Insert Node", "Delete Node", "Search Node", "In-order Traversal", "Pre-order Traversal", "Post-order Traversal", "← Back"});
        choice = InputUtils::getValidatedInput<int>("", 1, 7);

        switch (choice) {
            case 1:
                value = InputUtils::getValidatedInput<int>("Enter value to insert into BST: ");
                bst.insertNode(value);
                std::cout << UIUtils::GREEN << "Value inserted successfully." << UIUtils::RESET << std::endl;
                UIUtils::waitForEnter();
                break;
            case 2:
                value = InputUtils::getValidatedInput<int>("Enter value to delete from BST: ");
                bst.deleteNode(value);
                UIUtils::waitForEnter();
                break;
            case 3:
                value = InputUtils::getValidatedInput<int>("Enter value to search in BST: ");
                if (bst.searchNode(value)) {
                    std::cout << UIUtils::GREEN << "Value found in the tree." << UIUtils::RESET << std::endl;
                } else {
                    std::cout << UIUtils::RED << "Value not found in the tree." << UIUtils::RESET << std::endl;
                }
                UIUtils::waitForEnter();
                break;
            case 4:
                std::cout << "In-order traversal: ";
                bst.inOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 5:
                std::cout << "Pre-order traversal: ";
                bst.preOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 6:
                std::cout << "Post-order traversal: ";
                bst.postOrderTraversal();
                UIUtils::waitForEnter();
                break;
            case 7:
                return; // Back to main menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}