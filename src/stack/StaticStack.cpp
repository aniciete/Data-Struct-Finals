// src/stack/StaticStack.cpp
// Implementation of the StaticStack class for a stack with a fixed size.

#include "StaticStack.h"
#include <stdexcept> // Required for std::runtime_error
#include <iostream>  // Required for std::cout

/**
 * @brief Constructor for StaticStack.
 *
 * Initializes an empty stack by setting the top index to -1.
 */
StaticStack::StaticStack() {
    top = -1;
}

/**
 * @brief Checks if the stack is empty.
 *
 * @return true if the stack is empty (top is -1), false otherwise.
 */
bool StaticStack::isEmpty() {
    return top == -1;
}

/**
 * @brief Checks if the stack is full.
 *
 * @return true if the stack is full (top is at the maximum capacity), false otherwise.
 */
bool StaticStack::isFull() {
    return top == MAX_SIZE - 1;
}

/**
 * @brief Pushes a new value onto the top of the stack.
 *
 * If the stack is full, it throws a runtime_error. Otherwise, it increments
 * the top index and adds the new value to the array.
 *
 * @param value The integer value to be pushed onto the stack.
 * @throws std::runtime_error if the stack is full (stack overflow).
 */
void StaticStack::push(int value) {
    if (isFull()) {
        throw std::runtime_error("Stack overflow");
    }
    arr[++top] = value; // Increment top and then add the value
}

/**
 * @brief Pops the top element from the stack.
 *
 * If the stack is empty, it throws a runtime_error. Otherwise, it returns
 * the top element and decrements the top index.
 *
 * @return The value of the element that was at the top of the stack.
 * @throws std::runtime_error if the stack is empty (stack underflow).
 */
int StaticStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    return arr[top--]; // Return the value and then decrement top
}

/**
 * @brief Returns the value of the top element without removing it.
 *
 * If the stack is empty, it throws a runtime_error.
 *
 * @return The value of the element at the top of the stack.
 * @throws std::runtime_error if the stack is empty.
 */
int StaticStack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return arr[top];
}

/**
 * @brief Displays all the elements in the stack.
 *
 * Iterates through the stack from top to bottom and prints each element.
 * If the stack is empty, it prints a corresponding message.
 */
void StaticStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Gets the current top index of the stack.
 *
 * @return The index of the top element.
 */
int StaticStack::getTop() {
    return top;
}

/**
 * @brief Gets the current number of elements in the stack.
 *
 * @return The total number of elements in the stack.
 */
int StaticStack::size() {
    return top + 1;
}