#include <iostream>
#include "StaticQueue.h"

// Constructor: Initialize an empty queue
StaticQueue::StaticQueue() {
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

// Check if the queue is empty
bool StaticQueue::isEmpty() const {
    return count == 0;
}

// Check if the queue is full
bool StaticQueue::isFull() const {
    return count == MAX_SIZE;
}

// Add a new element to the rear of the queue
void StaticQueue::enqueue(int value) {
    if (isFull()) {
        throw std::runtime_error("Queue is full");
    }
    rearIndex = (rearIndex + 1) % MAX_SIZE;  // Circular array wrapping
    data[rearIndex] = value;
    count++;
}

// Remove the front element from the queue
void StaticQueue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    frontIndex = (frontIndex + 1) % MAX_SIZE;  // Circular array wrapping
    count--;
}

// Return the front element without removing it
int StaticQueue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[frontIndex];
}

// Return the rear element without removing it
int StaticQueue::rear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[rearIndex];
}

// Display all elements in the queue from front to rear
void StaticQueue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    std::cout << "Queue elements: ";
    for (int i = 0; i < count; ++i) {
        int index = (frontIndex + i) % MAX_SIZE;  // Handle circular array
        std::cout << data[index] << " ";
    }
    std::cout << "\n";
}

// Getter for the front index
int StaticQueue::getFront() const {
    return frontIndex;
}

// Getter for the rear index
int StaticQueue::getRear() const {
    return rearIndex;
}

// Getter for the current size
int StaticQueue::getSize() const {
    return count;
}
