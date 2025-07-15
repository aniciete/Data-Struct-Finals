#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <iostream>

struct Node {
    int data;
    Node* next;
};

class DynamicStack {
private:
    Node* top;

public:
    DynamicStack();
    ~DynamicStack();
    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    void display();
};

#endif // DYNAMIC_STACK_H