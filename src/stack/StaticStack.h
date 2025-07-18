// src/stack/StaticStack.h
// Definition of the StaticStack class, a stack with a fixed size.

#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <stdexcept>

/**
 * @class StaticStack
 * @brief A static stack implementation using a fixed-size array.
 *
 * This class provides all the basic stack operations, including push, pop, peek,
 * isEmpty, isFull, display, and size. The stack has a fixed capacity defined by MAX_SIZE.
 */
class StaticStack {
public:
    static const int MAX_SIZE = 100;  // The maximum capacity of the stack

private:
    int arr[MAX_SIZE];  // The array to store stack elements
    int top;            // The index of the top element in the stack

public:
    /**
     * @brief Constructor to initialize an empty stack.
     */
    StaticStack();

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Checks if the stack is full.
     * @return True if the stack is full, false otherwise.
     */
    bool isFull();

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
     * @brief Gets the index of the top element.
     * @return The index of the top element.
     */
    int getTop();

    /**
     * @brief Gets the current size of the stack.
     * @return The number of elements in the stack.
     */
    int size();
};

#endif // STATIC_STACK_H