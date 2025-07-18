// This header file defines the BinaryTree class, which represents a binary search tree.
// It includes the necessary headers and declares the class structure,
// including private helper functions for recursive operations and public methods for external interaction.

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"
#include <string>

/**
 * @class BinaryTree
 * @brief A class that implements a binary search tree.
 *
 * This class provides methods to insert, delete, search for, and traverse nodes in a binary search tree.
 * It uses a helper TreeNode class to represent the nodes of the tree.
 */
class BinaryTree {
private:
    TreeNode* root;  // Pointer to the root node of the tree

    // Private helper functions that implement the core logic using recursion.
    // These are not intended to be called directly from outside the class.

    TreeNode* insert(TreeNode* node, int data);
    TreeNode* remove(TreeNode* node, int data, bool& found);
    TreeNode* findMin(TreeNode* node);
    void inOrder(TreeNode* node);
    void getInOrder(TreeNode* node, std::string& result);
    void preOrder(TreeNode* node);
    void postOrder(TreeNode* node);
    bool search(TreeNode* node, int key);
    void destroyTree(TreeNode* node);

public:
    // Public interface for the BinaryTree class.
    // These methods provide a clean and simple way to interact with the tree.

    BinaryTree();
    ~BinaryTree();

    void insertNode(int data);
    void deleteNode(int data);
    bool searchNode(int key);

    // Traversal methods to display the tree's content in different orders.
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();

    // Method to get the in-order traversal as a string, useful for testing or display purposes.
    std::string getInOrderTraversal();
};

#endif // BINARY_TREE_H
