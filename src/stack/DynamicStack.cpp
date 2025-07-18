// src/stack/DynamicStack.cpp
// Implementation of the DynamicStack class for a stack with dynamic size.

#include "DynamicStack.h"
#include <stdexcept> // Required for std::runtime_error
#include <iostream>  // Required for std::cout

/**
 * @brief Constructor for DynamicStack.
 *
 * Initializes an empty stack by setting the top pointer to nullptr.
 */
DynamicStack::DynamicStack() {
    top = nullptr;
}

/**
 * @brief Destructor for DynamicStack.
 *
 * Frees all the memory allocated for the stack nodes to prevent memory leaks.
 * It does this by repeatedly calling pop() until the stack is empty.
 */
DynamicStack::~DynamicStack() {
    while (!isEmpty()) {
        pop();
    }
}

/**
 * @brief Checks if the stack is empty.
 *
 * @return true if the stack is empty (top is nullptr), false otherwise.
 */
bool DynamicStack::isEmpty() {
    return top == nullptr;
}

/**
 * @brief Pushes a new value onto the top of the stack.
 *
 * A new node is created and linked to the current top of the stack.
 * The top pointer is then updated to this new node.
 *
 * @param value The integer value to be pushed onto the stack.
 */
void DynamicStack::push(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;    // Set its data
    newNode->next = top;      // Link the new node to the previous top
    top = newNode;            // The new node is now the top
}

/**
 * @brief Pops the top element from the stack.
 *
 * If the stack is empty, it throws a runtime_error. Otherwise, it removes
 * the top element, deallocates its memory, and returns its value.
 *
 * @return The value of the element that was at the top of the stack.
 * @throws std::runtime_error if the stack is empty (stack underflow).
 */
int DynamicStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    int value = top->data; // Get the data from the top node
    Node* temp = top;      // Temporarily store the top node
    top = top->next;       // Move the top pointer to the next node
    delete temp;           // Free the memory of the original top node
    return value;
}

/**
 * @brief Returns the value of the top element without removing it.
 *
 * If the stack is empty, it throws a runtime_error.
 *
 * @return The value of the element at the top of the stack.
 * @throws std::runtime_error if the stack is empty.
 */
int DynamicStack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

/**
 * @brief Displays all the elements in the stack.
 *
 * Iterates through the stack from top to bottom and prints each element.
 * If the stack is empty, it prints a corresponding message.
 */
void DynamicStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    Node* current = top;
    std::cout << "Stack (top to bottom): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/**
 * @brief Gets the current number of elements in the stack.
 *
 * @return The total number of elements in the stack.
 */
int DynamicStack::size() {
    int count = 0;
    Node* temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}