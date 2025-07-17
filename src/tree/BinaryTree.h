#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"

// Binary search tree implementation
class BinaryTree {
private:
    TreeNode* root;  // Root node of the tree
    
    // Helper functions for recursive operations
    TreeNode* insert(TreeNode* node, int data);  // Insert a new node recursively
    TreeNode* remove(TreeNode* node, int data);  // Remove a node recursively
    TreeNode* findMin(TreeNode* node);  // Find the minimum value in the tree
    void inOrder(TreeNode* node);  // Perform inorder traversal recursively
    void preOrder(TreeNode* node);  // Perform preorder traversal recursively
    void postOrder(TreeNode* node);  // Perform postorder traversal recursively
    bool search(TreeNode* node, int key);  // Search for a value recursively

public:
    BinaryTree();                    // Constructor: Initialize empty tree
    ~BinaryTree();                   // Destructor: Clean up all nodes
    void insertNode(int data);       // Insert a value into the tree
    void deleteNode(int data);       // Delete a node with given value
    void inOrderTraversal();         // Display tree in inorder (left-root-right)
    void preOrderTraversal();        // Display tree in preorder (root-left-right)
    void postOrderTraversal();       // Display tree in postorder (left-right-root)
    bool searchNode(int key);        // Search for a value in the tree
    void destroyTree(TreeNode* node); // Helper function to destroy the tree
};

#endif // BINARY_TREE_H
