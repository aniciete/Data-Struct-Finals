// This file implements the BinaryTree class, which provides the core functionalities of a binary search tree.
// It includes methods for insertion, deletion, searching, and traversal (in-order, pre-order, post-order).
// The implementation uses recursion for many of its operations, ensuring clean and understandable code.

#include "BinaryTree.h"
#include <iostream>

/**
 * @brief Constructor for the BinaryTree class.
 *
 * Initializes the binary tree by setting the root to nullptr,
 * indicating that the tree is initially empty.
 */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
 * @brief Destructor for the BinaryTree class.
 *
 * Cleans up all nodes in the tree to prevent memory leaks.
 * It calls the destroyTree helper function starting from the root.
 */
BinaryTree::~BinaryTree() {
    destroyTree(root);
}

/**
 * @brief Recursively destroys all nodes in the tree.
 *
 * This is a helper function that traverses the tree in post-order,
 * deleting each node after its children have been deleted.
 *
 * @param node The current node to be destroyed.
 */
void BinaryTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);   // Recursively delete the left subtree
        destroyTree(node->right);  // Recursively delete the right subtree
        delete node;               // Delete the current node
    }
}

/**
 * @brief Recursively inserts a new node with the given data into the tree.
 *
 * This function finds the correct position for the new data and inserts a new node.
 * If the data already exists in the tree, it is ignored.
 *
 * @param node The current node in the traversal.
 * @param data The integer value to be inserted.
 * @return The node pointer after insertion.
 */
TreeNode* BinaryTree::insert(TreeNode* node, int data) {
    // If the current node is null, create a new node with the given data
    if (node == nullptr) {
        return new TreeNode(data);
    }

    // If the data is less than the current node's data, go to the left subtree
    if (data < node->data) {
        node->left = insert(node->left, data);
    // If the data is greater than the current node's data, go to the right subtree
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // If data is equal to node->data, do nothing (no duplicates allowed)

    return node;
}

/**
 * @brief Public method to insert a new value into the binary tree.
 *
 * This function serves as the entry point for inserting a new node.
 * It calls the recursive insert function starting from the root.
 *
 * @param data The integer value to be inserted.
 */
void BinaryTree::insertNode(int data) {
    root = insert(root, data);
}

/**
 * @brief Finds the node with the minimum value in a subtree.
 *
 * The minimum value in a binary search tree is always the leftmost node.
 *
 * @param node The root of the subtree to search in.
 * @return A pointer to the node with the minimum value.
 */
TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/**
 * @brief Recursively removes a node with the given value from the tree.
 *
 * This function handles three cases for deletion:
 * 1. The node is a leaf (no children).
 * 2. The node has one child.
 * 3. The node has two children.
 *
 * @param node The current node in the traversal.
 * @param data The value to be removed.
 * @param found A boolean reference to indicate if the value was found and removed.
 * @return The node pointer after deletion.
 */
TreeNode* BinaryTree::remove(TreeNode* node, int data, bool& found) {
    if (node == nullptr) {
        found = false;
        return node; // Value not found
    }

    if (data < node->data) {
        node->left = remove(node->left, data, found);
    } else if (data > node->data) {
        node->right = remove(node->right, data, found);
    } else {
        // Node with the value to be deleted found
        found = true;
        // Case 1: No child or one child
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Two children
        // Find the in-order successor (smallest in the right subtree)
        TreeNode* temp = findMin(node->right);
        // Copy the in-order successor's content to this node
        node->data = temp->data;
        // Delete the in-order successor
        node->right = remove(node->right, temp->data, found);
    }
    return node;
}

/**
 * @brief Public method to delete a value from the binary tree.
 *
 * This function initiates the deletion process and prints a confirmation message.
 *
 * @param data The integer value to be deleted.
 */
void BinaryTree::deleteNode(int data) {
    bool found = false;
    root = remove(root, data, found);
    if (found) {
        std::cout << "Value " << data << " has been deleted." << std::endl;
    } else {
        std::cout << "Value not found in tree." << std::endl;
    }
}

/**
 * @brief Recursively searches for a value in the tree.
 *
 * @param node The current node in the traversal.
 * @param key The value to search for.
 * @return True if the value is found, false otherwise.
 */
bool BinaryTree::search(TreeNode* node, int key) {
    if (node == nullptr) {
        return false;
    }

    if (key == node->data) {
        return true;
    } else if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

/**
 * @brief Public method to search for a value in the binary tree.
 *
 * @param key The value to search for.
 * @return True if the value is found, false otherwise.
 */
bool BinaryTree::searchNode(int key) {
    return search(root, key);
}

/**
 * @brief Performs in-order traversal of the tree (Left, Root, Right).
 *
 * This traversal visits nodes in ascending order of their values.
 *
 * @param node The current node in the traversal.
 */
void BinaryTree::inOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

/**
 * @brief Performs pre-order traversal of the tree (Root, Left, Right).
 *
 * @param node The current node in the traversal.
 */
void BinaryTree::preOrder(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

/**
 * @brief Performs post-order traversal of the tree (Left, Right, Root).
 *
 * @param node The current node in the traversal.
 */
void BinaryTree::postOrder(TreeNode* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
}

/**
 * @brief Public method to initiate an in-order traversal.
 *
 * Prints a message if the tree is empty, otherwise starts the traversal.
 */
void BinaryTree::inOrderTraversal() {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    inOrder(root);
    std::cout << std::endl;
}

/**
 * @brief Public method to initiate a pre-order traversal.
 */
void BinaryTree::preOrderTraversal() {
    preOrder(root);
    std::cout << std::endl;
}

/**
 * @brief Public method to initiate a post-order traversal.
 */
void BinaryTree::postOrderTraversal() {
    postOrder(root);
    std::cout << std::endl;
}

/**
 * @brief Helper function to get the in-order traversal as a string.
 *
 * This is used to return the tree's content without printing it to the console.
 *
 * @param node The current node in the traversal.
 * @param result The string to append the traversal result to.
 */
void BinaryTree::getInOrder(TreeNode* node, std::string& result) {
    if (node == nullptr) {
        return;
    }
    getInOrder(node->left, result);
    result += std::to_string(node->data) + " ";
    getInOrder(node->right, result);
}

/**
 * @brief Public method to get the in-order traversal as a string.
 *
 * @return A string containing the space-separated values of the in-order traversal.
 */
std::string BinaryTree::getInOrderTraversal() {
    std::string result = "";
    getInOrder(root, result);
    if (!result.empty()) {
        result.pop_back(); // Remove the trailing space
    }
    return result;
}
