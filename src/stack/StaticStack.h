#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <stdexcept>

// Static stack implementation using fixed-size array
class StaticStack {
public:
    static const int MAX_SIZE = 100;  // Maximum stack capacity

private:
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
    int getTop();            // Getter for the top index
    int size();              // Getter for the current size
};

#endif // STATIC_STACK_H