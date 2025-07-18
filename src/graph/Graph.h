#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <queue>
#include "GraphNode.h"

/**
 * @class Graph
 * @brief Represents an undirected graph data structure using an adjacency list.
 *
 * This class provides functionalities to manage a graph, including adding and
 * removing vertices and edges, displaying the graph's structure, and
 * performing graph traversals.
 */
class Graph {
private:
    /**
     * @brief A map storing the graph's vertices, where the key is the vertex
     * value and the value is a pointer to the GraphNode object.
     */
    std::map<int, GraphNode*> nodes;

public:
    /**
     * @brief Destructor for the Graph class.
     *
     * Cleans up all dynamically allocated GraphNode objects to prevent memory leaks.
     */
    ~Graph();

    /**
     * @brief Adds a new vertex to the graph.
     * @param value The integer value of the vertex to be added.
     */
    void addVertex(int value);

    /**
     * @brief Adds an undirected edge between two existing vertices.
     * @param v1 The value of the first vertex.
     * @param v2 The value of the second vertex.
     */
    void addEdge(int v1, int v2);

    /**
     * @brief Removes a vertex and all its incident edges from the graph.
     * @param value The value of the vertex to be removed.
     */
    void removeVertex(int value);

    /**
     * @brief Removes the edge between two specified vertices.
     * @param v1 The value of the first vertex.
     * @param v2 The value of the second vertex.
     */
    void removeEdge(int v1, int v2);

    /**
     * @brief Displays the graph's adjacency list representation in the console.
     */
    void display();

    /**
     * @brief Performs a Breadth-First Search (BFS) traversal starting from a given vertex.
     * @param startValue The value of the vertex to start the traversal from.
     */
    void traverse(int startValue);

    /**
     * @brief Gets the BFS traversal sequence as a string.
     * @param startValue The value of the vertex to start the traversal from.
     * @return A string representing the BFS traversal path.
     */
    std::string getTraversal(int startValue);
};

#endif // GRAPH_H
