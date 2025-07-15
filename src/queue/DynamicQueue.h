#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

class DynamicQueue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;

public:
    DynamicQueue();
    ~DynamicQueue();
    bool isEmpty() const;
    void enqueue(int value);
    void dequeue();
    int front() const;
    int rear() const;
    void display() const;
};

#endif
