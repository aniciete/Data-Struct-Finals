#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100; // Maximum size of the stack

// Static stack implementation using fixed-size array
class StaticStack {
private:
    static const int MAX_SIZE = 100;  // Maximum stack capacity
    int arr[MAX_SIZE];                // Array to store stack elements
    int top;                          // Index of the top element

public:
    StaticStack();           // Constructor: Initialize empty stack
    bool isEmpty();          // Check if stack is empty
    bool isFull();           // Check if stack is full
    void push(int value);    // Add element to top of stack
    int pop();               // Remove and return top element
    int peek();              // Return top element without removing
    void display();          // Display all stack elements
};

#endif // STATIC_STACK_H