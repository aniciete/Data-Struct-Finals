#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>

class Graph {
private:
    std::map<int, std::vector<int>> adjList;

public:
    void addVertex(int vertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertex);
    void removeEdge(int vertex1, int vertex2);
    void display();
    void traverse(int startVertex);
};

#endif
