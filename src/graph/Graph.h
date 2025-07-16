#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <queue>
#include "graph/GraphNode.h"

class Graph {
private:
    std::map<int, GraphNode*> nodes;

public:
    ~Graph(); // Destructor to free memory

    void addVertex(int value);
    void addEdge(int v1, int v2);
    void removeVertex(int value);
    void removeEdge(int v1, int v2);
    void display();
    void traverse(int startValue);
};

#endif // GRAPH_H
