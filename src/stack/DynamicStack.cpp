#include "DynamicStack.h"
#include <stdexcept>

// Constructor: Initialize an empty stack
DynamicStack::DynamicStack() {
    top = nullptr;
}

// Destructor: Clean up all nodes to prevent memory leaks
DynamicStack::~DynamicStack() {
    while (!isEmpty()) {
        pop();
    }
}

// Check if the stack is empty
bool DynamicStack::isEmpty() {
    return top == nullptr;
}

// Add a new element to the top of the stack
void DynamicStack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;  // Link to previous top
    top = newNode;        // Update top pointer
}

// Remove and return the top element from the stack
int DynamicStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;  // Move top to next node
    delete temp;      // Free memory
    return value;
}

// Return the top element without removing it
int DynamicStack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

// Display all elements in the stack from top to bottom
void DynamicStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}