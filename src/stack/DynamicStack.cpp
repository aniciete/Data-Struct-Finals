#include "DynamicStack.h"

DynamicStack::DynamicStack() {
    top = nullptr;
}

DynamicStack::~DynamicStack() {
    while (!isEmpty()) {
        pop();
    }
}

bool DynamicStack::isEmpty() {
    return top == nullptr;
}

void DynamicStack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int DynamicStack::pop() {
    if (isEmpty()) {
        std::cout << "Stack underflow\n";
        return -1; // Return a sentinel value
    }
    int value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

int DynamicStack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return -1; // Return a sentinel value
    }
    return top->data;
}

void DynamicStack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}