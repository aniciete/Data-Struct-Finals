#include <iostream>
#include "StaticQueue.h"

StaticQueue::StaticQueue() {
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

bool StaticQueue::isEmpty() const {
    return count == 0;
}

bool StaticQueue::isFull() const {
    return count == MAX_SIZE;
}

void StaticQueue::enqueue(int value) {
    if (isFull()) {
        std::cout << "Queue is full\n";
        return;
    }
    rearIndex = (rearIndex + 1) % MAX_SIZE;
    data[rearIndex] = value;
    count++;
}

void StaticQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
}

int StaticQueue::front() const {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return data[frontIndex];
}

int StaticQueue::rear() const {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return data[rearIndex];
}

void StaticQueue::display() const {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return;
    }
    std::cout << "Queue elements: ";
    for (int i = 0; i < count; ++i) {
        int index = (frontIndex + i) % MAX_SIZE;
        std::cout << data[index] << " ";
    }
    std::cout << "\n";
}
