#include "StaticStack.h"

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
        std::cout << "Stack overflow\n";
        return;
    }
    arr[++top] = value;
}

int StaticStack::pop() {
    if (isEmpty()) {
        std::cout << "Stack underflow\n";
        return -1; // Return a sentinel value
    }
    return arr[top--];
}

int StaticStack::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty\n";
        return -1; // Return a sentinel value
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