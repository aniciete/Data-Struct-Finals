#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

/**
 * @class GraphNode
 * @brief Represents a single node (or vertex) in a graph.
 *
 * Each GraphNode contains an integer value and a list of pointers to its
 * neighboring nodes, forming an adjacency list representation for that node.
 */
class GraphNode {
public:
    /**
     * @brief The integer value stored in the node.
     *
     * This value serves as a unique identifier for the vertex in the graph.
     */
    int value;

    /**
     * @brief A vector of pointers to adjacent GraphNode objects.
     *
     * This list represents the edges connecting this node to its neighbors.
     */
    std::vector<GraphNode*> neighbors;

    /**
     * @brief Constructs a new GraphNode with a specified value.
     * @param val The integer value to assign to the node.
     */
    GraphNode(int val) : value(val) {}
};

#endif // GRAPHNODE_H
