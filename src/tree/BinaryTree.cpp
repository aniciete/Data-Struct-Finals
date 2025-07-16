#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(TreeNode* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

TreeNode* BinaryTree::insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

TreeNode* BinaryTree::deleteNode(TreeNode* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

void BinaryTree::deleteNode(int value) {
    root = deleteNode(root, value);
}

bool BinaryTree::search(TreeNode* node, int value) {
    if (node == nullptr)
        return false;

    if (value == node->data)
        return true;
    else if (value < node->data)
        return search(node->left, value);
    else
        return search(node->right, value);
}

bool BinaryTree::search(int value) {
    return search(root, value);
}

void BinaryTree::inorder(TreeNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void BinaryTree::preorder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BinaryTree::postorder(TreeNode* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

void BinaryTree::inorder() {
    inorder(root);
    cout << endl;
}

void BinaryTree::preorder() {
    preorder(root);
    cout << endl;
}

void BinaryTree::postorder() {
    postorder(root);
    cout << endl;
}
