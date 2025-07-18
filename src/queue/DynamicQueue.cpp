#include <iostream>
#include "DynamicQueue.h"

/**
 * @brief Constructor for DynamicQueue.
 *
 * Initializes an empty queue by setting front and rear pointers to nullptr.
 * This indicates that the queue has no nodes upon creation.
 */
DynamicQueue::DynamicQueue() {
    frontNode = nullptr;
    rearNode = nullptr;
}

/**
 * @brief Destructor for DynamicQueue.
 *
 * Cleans up all dynamically allocated nodes in the queue to prevent memory leaks.
 * It repeatedly dequeues nodes until the queue is empty.
 */
DynamicQueue::~DynamicQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

/**
 * @brief Checks if the queue is empty.
 *
 * @return true if the queue is empty (frontNode is nullptr), false otherwise.
 */
bool DynamicQueue::isEmpty() const {
    return frontNode == nullptr;
}

/**
 * @brief Adds a new element to the rear of the queue.
 *
 * @param value The integer value to be added to the queue.
 *
 * A new node is created with the given value. If the queue is empty,
 * both front and rear pointers are set to the new node. Otherwise, the new
 * node is linked to the current rear, and the rear pointer is updated.
 */
void DynamicQueue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        frontNode = rearNode = newNode;  // First element
    } else {
        rearNode->next = newNode;        // Link to current rear
        rearNode = newNode;              // Update rear pointer
    }
}

/**
 * @brief Removes the front element from the queue.
 *
 * If the queue is empty, it throws a runtime error. Otherwise, it removes
 * the front node, advances the front pointer, and deallocates the memory
 * of the removed node. If the queue becomes empty after dequeue, the rear
 * pointer is also set to nullptr.
 */
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

/**
 * @brief Returns the front element of the queue without removing it.
 *
 * @return The integer value of the front element.
 *
 * Throws a runtime error if the queue is empty.
 */
int DynamicQueue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return frontNode->data;
}

/**
 * @brief Returns the rear element of the queue without removing it.
 *
 * @return The integer value of the rear element.
 *
 * Throws a runtime error if the queue is empty.
 */
int DynamicQueue::rear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return rearNode->data;
}

/**
 * @brief Displays all elements in the queue from front to rear.
 *
 * If the queue is empty, it prints a message. Otherwise, it iterates
 * through the queue from the front node to the rear and prints the
 * data of each node.
 */
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

/**
 * @brief Gets the current size of the queue.
 *
 * @return The number of elements in the queue.
 *
 * It iterates through the queue and counts the number of nodes.
 */
int DynamicQueue::getSize() const {
    int size = 0;
    Node* current = frontNode;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}
