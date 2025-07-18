#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdexcept>

/**
 * @class DynamicQueue
 * @brief A class that implements a dynamic queue using a linked list.
 *
 * This class provides standard queue operations such as enqueue, dequeue,
 * front, rear, and checking if the queue is empty. It dynamically allocates
 * memory for nodes, so it can grow as needed.
 */
class DynamicQueue {
private:
    /**
     * @struct Node
     * @brief A structure to represent a node in the linked list.
     *
     * Each node contains an integer data value and a pointer to the next
     * node in the queue.
     */
    struct Node {
        int data;    // Value stored in the node
        Node* next;  // Pointer to the next node
    };

    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue

public:
    /**
     * @brief Constructor to initialize an empty queue.
     */
    DynamicQueue();

    /**
     * @brief Destructor to clean up all nodes and prevent memory leaks.
     */
    ~DynamicQueue();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Adds an element to the rear of the queue.
     * @param value The integer value to be added.
     */
    void enqueue(int value);

    /**
     * @brief Removes the element from the front of the queue.
     */
    void dequeue();

    /**
     * @brief Returns the front element without removing it.
     * @return The value of the front element.
     */
    int front() const;

    /**
     * @brief Returns the rear element without removing it.
     * @return The value of the rear element.
     */
    int rear() const;

    /**
     * @brief Displays all elements in the queue.
     */
    void display() const;

    /**
     * @brief Gets the current size of the queue.
     * @return The number of elements in the queue.
     */
    int getSize() const;
};

#endif // DYNAMIC_QUEUE_H
