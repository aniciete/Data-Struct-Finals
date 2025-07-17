#include <iostream>
#include "DynamicQueue.h"

DynamicQueue::DynamicQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}

DynamicQueue::~DynamicQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool DynamicQueue::isEmpty() const {
    return frontNode == nullptr;
}

void DynamicQueue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void DynamicQueue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
}

int DynamicQueue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return frontNode->data;
}

int DynamicQueue::rear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return rearNode->data;
}

void DynamicQueue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    std::cout << "Queue elements: ";
    Node* current = frontNode;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}
