#include <iostream>
#include "StaticQueue.h"

/**
 * @brief Constructor for StaticQueue.
 *
 * Initializes an empty queue. The `frontIndex` is set to 0, `rearIndex` to -1,
 * and `count` to 0, indicating that the queue is empty.
 */
StaticQueue::StaticQueue() {
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

/**
 * @brief Checks if the queue is empty.
 *
 * @return true if the queue's element count is 0, false otherwise.
 */
bool StaticQueue::isEmpty() const {
    return count == 0;
}

/**
 * @brief Checks if the queue is full.
 *
 * @return true if the element count has reached `MAX_SIZE`, false otherwise.
 */
bool StaticQueue::isFull() const {
    return count == MAX_SIZE;
}

/**
 * @brief Adds a new element to the rear of the queue.
 *
 * @param value The integer value to be added.
 *
 * Throws a `std::runtime_error` if the queue is full. Otherwise, it calculates
 * the new rear index using modular arithmetic for the circular array, inserts
 * the value, and increments the element count.
 */
void StaticQueue::enqueue(int value) {
    if (isFull()) {
        throw std::runtime_error("Queue is full");
    }
    rearIndex = (rearIndex + 1) % MAX_SIZE;  // Circular array wrapping
    data[rearIndex] = value;
    count++;
}

/**
 * @brief Removes the front element from the queue.
 *
 * Throws a `std::runtime_error` if the queue is empty. Otherwise, it moves
 * the `frontIndex` forward using modular arithmetic and decrements the count.
 */
void StaticQueue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    frontIndex = (frontIndex + 1) % MAX_SIZE;  // Circular array wrapping
    count--;
}

/**
 * @brief Returns the front element without removing it.
 *
 * @return The integer value of the front element.
 *
 * Throws a `std::runtime_error` if the queue is empty.
 */
int StaticQueue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[frontIndex];
}

/**
 * @brief Returns the rear element without removing it.
 *
 * @return The integer value of the rear element.
 *
 * Throws a `std::runtime_error` if the queue is empty.
 */
int StaticQueue::rear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[rearIndex];
}

/**
 * @brief Displays all elements in the queue from front to rear.
 *
 * If the queue is empty, it prints a message. Otherwise, it iterates through
 * the elements from the `frontIndex` and prints them, handling the circular
 * nature of the array.
 */
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

/**
 * @brief Getter for the front index.
 *
 * @return The current front index of the queue.
 */
int StaticQueue::getFront() const {
    return frontIndex;
}

/**
 * @brief Getter for the rear index.
 *
 * @return The current rear index of the queue.
 */
int StaticQueue::getRear() const {
    return rearIndex;
}

/**
 * @brief Getter for the current size of the queue.
 *
 * @return The number of elements currently in the queue.
 */
int StaticQueue::getSize() const {
    return count;
}
