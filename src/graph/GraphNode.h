#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

// Represents a single node (vertex) in the graph
class GraphNode {
public:
    int value; // Value or label of the vertex
    std::vector<GraphNode*> neighbors; // List of adjacent nodes

    // Constructor: Initialize node with a value
    GraphNode(int val) : value(val) {}
};

#endif // GRAPHNODE_H
