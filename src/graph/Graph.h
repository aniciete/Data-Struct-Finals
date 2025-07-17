#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <queue>
#include "graph/GraphNode.h"

// Represents an undirected graph using adjacency lists
class Graph {
private:
    // Map of vertex value to its corresponding node
    std::map<int, GraphNode*> nodes;

public:
    ~Graph(); // Destructor to free memory and clean up nodes

    // Add a vertex with the given value
    void addVertex(int value);
    // Add an edge between two vertices
    void addEdge(int v1, int v2);
    // Remove the vertex with the given value
    void removeVertex(int value);
    // Remove the edge between two vertices
    void removeEdge(int v1, int v2);
    // Display the adjacency list of the graph
    void display();
    // Traverse the graph using BFS starting from a vertex
    void traverse(int startValue);
};

#endif // GRAPH_H
