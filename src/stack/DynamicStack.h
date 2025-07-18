// src/stack/DynamicStack.h
// Definition of the DynamicStack class, a stack with dynamic size.

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
#include <stdexcept>

/**
 * @brief Node structure for the linked list implementation of the stack.
 *
 * Each node contains an integer value and a pointer to the next node in the stack.
 */
struct Node {
    int data;    // The value stored in the node
    Node* next;  // Pointer to the next node in the stack
};

/**
 * @class DynamicStack
 * @brief A dynamic stack implementation using a linked list.
 *
 * This class provides all the basic stack operations, including push, pop, peek,
 * isEmpty, display, and size. The stack can grow and shrink as needed.
 */
class DynamicStack {
private:
    Node* top;   // Pointer to the top of the stack

public:
    /**
     * @brief Constructor to initialize an empty stack.
     */
    DynamicStack();

    /**
     * @brief Destructor to clean up all nodes and prevent memory leaks.
     */
    ~DynamicStack();

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Adds an element to the top of the stack.
     * @param value The integer value to be added.
     */
    void push(int value);

    /**
     * @brief Removes and returns the top element of the stack.
     * @return The value of the top element.
     */
    int pop();

    /**
     * @brief Returns the top element without removing it.
     * @return The value of the top element.
     */
    int peek();

    /**
     * @brief Displays all elements in the stack from top to bottom.
     */
    void display();

    /**
     * @brief Gets the current size of the stack.
     * @return The number of elements in the stack.
     */
    int size();
};

#endif // DYNAMIC_STACK_H