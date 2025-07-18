#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include <stdexcept>

// Dynamic queue implementation using linked list
class DynamicQueue {
private:
    // Node structure for linked list implementation
    struct Node {
        int data;    // Value stored in the node
        Node* next;  // Pointer to the next node
    };
    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue

public:
    DynamicQueue();           // Constructor: Initialize empty queue
    ~DynamicQueue();          // Destructor: Clean up all nodes
    bool isEmpty() const;     // Check if queue is empty
    void enqueue(int value);  // Add element to rear of queue
    void dequeue();           // Remove element from front of queue
    int front() const;        // Return front element without removing
    int rear() const;         // Return rear element without removing
    void display() const;     // Display all queue elements
    int getSize() const;      // Get the current size of the queue
};

#endif // DYNAMIC_QUEUE_H
