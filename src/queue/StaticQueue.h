#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdexcept>

/**
 * @class StaticQueue
 * @brief A class that implements a static queue using a fixed-size circular array.
 *
 * This class provides standard queue operations like enqueue, dequeue, front, and rear.
 * It has a fixed capacity defined by `MAX_SIZE`.
 */
class StaticQueue {
private:
    static const int MAX_SIZE = 100;  // Maximum queue capacity
    int data[MAX_SIZE];               // Array to store queue elements
    int frontIndex;                   // Index of the front element
    int rearIndex;                    // Index of the rear element
    int count;                        // Current number of elements

public:
    /**
     * @brief Constructor to initialize an empty queue.
     */
    StaticQueue();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Checks if the queue is full.
     * @return True if the queue is full, false otherwise.
     */
    bool isFull() const;

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
     * @brief Getter for the front index.
     * @return The current front index.
     */
    int getFront() const;

    /**
     * @brief Getter for the rear index.
     * @return The current rear index.
     */
    int getRear() const;

    /**
     * @brief Getter for the current size of the queue.
     * @return The number of elements in the queue.
     */
    int getSize() const;
};

#endif // STATIC_QUEUE_H
