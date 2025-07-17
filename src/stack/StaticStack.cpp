#include "StaticStack.h"
#include <stdexcept>

StaticStack::StaticStack() {
    top = -1;
}

bool StaticStack::isEmpty() {
    return top == -1;
}

bool StaticStack::isFull() {
    return top == MAX_SIZE - 1;
}

void StaticStack::push(int value) {
    if (isFull()) {
        throw std::runtime_error("Stack overflow");
    }
    arr[++top] = value;
}

int StaticStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    return arr[top--];
}

int StaticStack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return arr[top];
}

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