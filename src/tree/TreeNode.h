#ifndef TREE_NODE_H
#define TREE_NODE_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

#endif // TREE_NODE_H
