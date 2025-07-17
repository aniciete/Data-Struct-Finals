#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>
#include <stdexcept>

// Node structure for linked list implementation
struct Node {
    int data;    // Value stored in the node
    Node* next;  // Pointer to the next node
};

// Dynamic stack implementation using linked list
class DynamicStack {
private:
    Node* top;   // Pointer to the top of the stack

public:
    DynamicStack();           // Constructor: Initialize empty stack
    ~DynamicStack();          // Destructor: Clean up all nodes
    bool isEmpty();           // Check if stack is empty
    void push(int value);     // Add element to top of stack
    int pop();                // Remove and return top element
    int peek();               // Return top element without removing
    void display();           // Display all stack elements
};

#endif // DYNAMIC_STACK_H