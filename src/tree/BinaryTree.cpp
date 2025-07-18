#include "BinaryTree.h"
#include <iostream>

// Constructor: Initialize an empty binary tree
BinaryTree::BinaryTree() {
    root = nullptr;
}

// Destructor: Clean up all nodes to prevent memory leaks
BinaryTree::~BinaryTree() {
    destroyTree(root);
}

// Recursively destroy all nodes in the tree
void BinaryTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);   // Delete left subtree
        destroyTree(node->right);  // Delete right subtree
        delete node;               // Delete current node
    }
}

// Recursively insert a new node in the correct position
TreeNode* BinaryTree::insert(TreeNode* node, int data) {
    if (node == nullptr) {
        return new TreeNode(data);  // Create new node if position is empty
    }

    if (data < node->data) {
        node->left = insert(node->left, data);   // Insert in left subtree
    } else if (data > node->data) {
        node->right = insert(node->right, data); // Insert in right subtree
    }
    // Ignore duplicates

    return node;
}

// Public interface to insert a node into the tree
void BinaryTree::insertNode(int data) {
    root = insert(root, data);
}

// Find the minimum value node (leftmost node)
TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// Recursively remove a node with the given value
TreeNode* BinaryTree::remove(TreeNode* node, int data, bool& found) {
    if (node == nullptr) {
        found = false;
        return node;  // Node not found
    }

    if (data < node->data) {
        node->left = remove(node->left, data, found);   // Search in left subtree
    } else if (data > node->data) {
        node->right = remove(node->right, data, found); // Search in right subtree
    } else {
        // Node to be deleted found
        found = true;
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;  // Replace with right child
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;  // Replace with left child
        }

        // Node has two children: find inorder successor
        TreeNode* temp = findMin(node->right);
        node->data = temp->data;  // Replace data with successor
        // Since the successor is guaranteed to be found, we can reuse the `found` flag.
        node->right = remove(node->right, temp->data, found);  // Delete successor
    }

    return node;
}

// Public interface to delete a node from the tree
void BinaryTree::deleteNode(int data) {
    bool found = false;
    root = remove(root, data, found);
    if (found) {
        std::cout << "Value " << data << " has been deleted." << std::endl;
    } else {
        std::cout << "Value not found in tree." << std::endl;
    }
}

// Recursively search for a value in the tree
bool BinaryTree::search(TreeNode* node, int key) {
    if (node == nullptr)
        return false;  // Value not found

    if (key == node->data)
        return true;   // Value found
    else if (key < node->data)
        return search(node->left, key);   // Search in left subtree
    else
        return search(node->right, key);  // Search in right subtree
}

// Public interface to search for a value in the tree
bool BinaryTree::searchNode(int key) {
    return search(root, key);
}

// Inorder traversal: left -> root -> right (sorted order)
void BinaryTree::inOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

// Preorder traversal: root -> left -> right
void BinaryTree::preOrder(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";   // Visit root
        preOrder(node->left);             // Visit left subtree
        preOrder(node->right);            // Visit right subtree
    }
}

// Postorder traversal: left -> right -> root
void BinaryTree::postOrder(TreeNode* node) {
    if (node != nullptr) {
        postOrder(node->left);            // Visit left subtree
        postOrder(node->right);           // Visit right subtree
        std::cout << node->data << " ";   // Visit root
    }
}

// Public interface for inorder traversal
void BinaryTree::inOrderTraversal() {
    if (root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    inOrder(root);
    std::cout << std::endl;
}

// Public interface for preorder traversal
void BinaryTree::preOrderTraversal() {
    preOrder(root);
    std::cout << std::endl;
}

// Public interface for postorder traversal
void BinaryTree::postOrderTraversal() {
    postOrder(root);
    std::cout << std::endl;
}

// Helper function to get in-order traversal as a string
void BinaryTree::getInOrder(TreeNode* node, std::string& result) {
    if (node == nullptr) {
        return;
    }
    getInOrder(node->left, result);
    result += std::to_string(node->data) + " ";
    getInOrder(node->right, result);
}

// Public interface to get in-order traversal as a string
std::string BinaryTree::getInOrderTraversal() {
    std::string result = "";
    getInOrder(root, result);
    // Trim trailing space
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}
