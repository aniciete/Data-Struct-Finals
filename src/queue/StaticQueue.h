#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdexcept>

// Static queue implementation using fixed-size array
class StaticQueue {
private:
    static const int MAX_SIZE = 100;  // Maximum queue capacity
    int data[MAX_SIZE];               // Array to store queue elements
    int frontIndex;                   // Index of the front element
    int rearIndex;                    // Index of the rear element
    int count;                        // Current number of elements

public:
    StaticQueue();           // Constructor: Initialize empty queue
    bool isEmpty() const;    // Check if queue is empty
    bool isFull() const;     // Check if queue is full
    void enqueue(int value); // Add element to rear of queue
    void dequeue();          // Remove element from front of queue
    int front() const;       // Return front element without removing
    int rear() const;        // Return rear element without removing
    void display() const;    // Display all queue elements
};

#endif // STATIC_QUEUE_H
