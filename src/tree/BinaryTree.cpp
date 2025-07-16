#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

TreeNode* BinaryTree::insert(TreeNode* node, int data) {
    if (node == nullptr) {
        return new TreeNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

void BinaryTree::insertNode(int data) {
    root = insert(root, data);
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

TreeNode* BinaryTree::remove(TreeNode* node, int data) {
    if (node == nullptr)
        return node;

    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
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
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BinaryTree::deleteNode(int data) {
    root = remove(root, data);
}

bool BinaryTree::search(TreeNode* node, int key) {
    if (node == nullptr)
        return false;

    if (key == node->data)
        return true;
    else if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

bool BinaryTree::searchNode(int key) {
    return search(root, key);
}

void BinaryTree::inOrder(TreeNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}

void BinaryTree::preOrder(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::postOrder(TreeNode* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
}

void BinaryTree::inOrderTraversal() {
    inOrder(root);
    std::cout << std::endl;
}

void BinaryTree::preOrderTraversal() {
    preOrder(root);
    std::cout << std::endl;
}

void BinaryTree::postOrderTraversal() {
    postOrder(root);
    std::cout << std::endl;
}
