#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"

class BinaryTree {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int data);
    TreeNode* remove(TreeNode* node, int data);
    TreeNode* findMin(TreeNode* node);
    void inOrder(TreeNode* node);
    void preOrder(TreeNode* node);
    void postOrder(TreeNode* node);
    bool search(TreeNode* node, int key);

public:
    BinaryTree();
    ~BinaryTree();
    void insertNode(int data);
    void deleteNode(int data);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    bool searchNode(int key);
    void destroyTree(TreeNode* node);
};

#endif // BINARY_TREE_H
