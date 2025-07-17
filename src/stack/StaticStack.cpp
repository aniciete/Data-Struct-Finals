#include "StaticStack.h"
#include <stdexcept>

// Constructor: Initialize an empty stack (top = -1 means empty)
StaticStack::StaticStack() {
    top = -1;
}

// Check if the stack is empty
bool StaticStack::isEmpty() {
    return top == -1;
}

// Check if the stack is full
bool StaticStack::isFull() {
    return top == MAX_SIZE - 1;
}

// Add a new element to the top of the stack
void StaticStack::push(int value) {
    if (isFull()) {
        throw std::runtime_error("Stack overflow");
    }
    arr[++top] = value;  // Increment top and add value
}

// Remove and return the top element from the stack
int StaticStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    return arr[top--];  // Return value and decrement top
}

// Return the top element without removing it
int StaticStack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return arr[top];
}

// Display all elements in the stack from top to bottom
void StaticStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    for (int i = top; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}