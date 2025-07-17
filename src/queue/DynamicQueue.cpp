#include <iostream>
#include "DynamicQueue.h"

// Constructor: Initialize an empty queue
DynamicQueue::DynamicQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}

// Destructor: Clean up all nodes to prevent memory leaks
DynamicQueue::~DynamicQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Check if the queue is empty
bool DynamicQueue::isEmpty() const {
    return frontNode == nullptr;
}

// Add a new element to the rear of the queue
void DynamicQueue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        frontNode = rearNode = newNode;  // First element
    } else {
        rearNode->next = newNode;        // Link to current rear
        rearNode = newNode;              // Update rear pointer
    }
}

// Remove the front element from the queue
void DynamicQueue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;  // Move front to next node
    delete temp;                  // Free memory
    if (frontNode == nullptr) {
        rearNode = nullptr;       // Queue is now empty
    }
}

// Return the front element without removing it
int DynamicQueue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return frontNode->data;
}

// Return the rear element without removing it
int DynamicQueue::rear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return rearNode->data;
}

// Display all elements in the queue from front to rear
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
