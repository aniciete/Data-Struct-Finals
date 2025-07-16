#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

class GraphNode {
public:
    int value;
    std::vector<GraphNode*> neighbors;

    GraphNode(int val) : value(val) {}
};

#endif
