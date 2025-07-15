#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

class StaticQueue {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int frontIndex;
    int rearIndex;
    int count;

public:
    StaticQueue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int value);
    void dequeue();
    int front() const;
    int rear() const;
    void display() const;
};

#endif
