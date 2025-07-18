// This header file defines the TreeNode struct, which is the basic building block for the BinaryTree class.
// Each TreeNode represents a single node in the binary tree, containing a value and pointers to its children.

#ifndef TREE_NODE_H
#define TREE_NODE_H

/**
 * @struct TreeNode
 * @brief Represents a single node in a binary tree.
 *
 * This struct holds an integer value and pointers to the left and right child nodes.
 * It provides a constructor for easy initialization of a new node.
 */
struct TreeNode {
    int data;         // The integer value stored in the node.
    TreeNode* left;   // Pointer to the left child node.
    TreeNode* right;  // Pointer to the right child node.

    /**
     * @brief Constructor for TreeNode.
     *
     * Initializes a new node with a given value and sets its left and right children to nullptr.
     * @param val The integer value to be stored in the node.
     */
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // TREE_NODE_H
