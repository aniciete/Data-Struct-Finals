#ifndef TREE_NODE_H
#define TREE_NODE_H

// Node class for binary tree implementation
struct TreeNode {
    int data;         // Value stored in the node
    TreeNode* left;   // Pointer to left child
    TreeNode* right;  // Pointer to right child

    // Constructor: Initialize node with value and null children
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // TREE_NODE_H
