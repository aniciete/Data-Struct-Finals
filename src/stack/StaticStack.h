#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
#include <stdexcept>

const int MAX_SIZE = 100; // Maximum size of the stack

class StaticStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    StaticStack();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int peek();
    void display();
};

#endif // STATIC_STACK_H