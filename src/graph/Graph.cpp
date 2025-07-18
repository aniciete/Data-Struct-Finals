#include "Graph.h"

// Destructor: Clean up all dynamically allocated nodes
Graph::~Graph() {
    for (auto& pair : nodes) {
        delete pair.second;
    }
}

// Add a new vertex to the graph if it doesn't already exist
void Graph::addVertex(int value) {
    if (nodes.find(value) == nodes.end()) {
        nodes[value] = new GraphNode(value);
        std::cout << "Vertex " << value << " added.\n";
    } else {
        std::cout << "Vertex already exists.\n";
    }
}

// Add an undirected edge between two existing vertices
void Graph::addEdge(int v1, int v2) {
    if (nodes.find(v1) != nodes.end() && nodes.find(v2) != nodes.end()) {
        GraphNode* node1 = nodes[v1];
        GraphNode* node2 = nodes[v2];

        // Avoid duplicate edges
        bool exists = false;
        for (auto neighbor : node1->neighbors) {
            if (neighbor->value == v2) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            node1->neighbors.push_back(node2);
            node2->neighbors.push_back(node1);
            std::cout << "Edge added between " << v1 << " and " << v2 << ".\n";
        } else {
            std::cout << "Edge already exists.\n";
        }
    } else {
        std::cout << "One or both vertices do not exist.\n";
    }
}

// Remove a vertex and all its associated edges from the graph
void Graph::removeVertex(int value) {
    auto it = nodes.find(value);
    if (it == nodes.end()) {
        std::cout << "Vertex does not exist.\n";
        return;
    }

    GraphNode* toRemove = it->second;

    // Remove all edges connected to this vertex
    for (auto& pair : nodes) {
        GraphNode* node = pair.second;
        if (node != toRemove) {
            node->neighbors.erase(
                std::remove(node->neighbors.begin(), node->neighbors.end(), toRemove),
                node->neighbors.end()
            );
        }
    }

    // Now, remove the vertex itself
    delete toRemove;
    nodes.erase(it);
    std::cout << "Vertex " << value << " removed.\n";
}

// Remove the edge between two vertices if both exist
void Graph::removeEdge(int v1, int v2) {
    if (nodes.find(v1) != nodes.end() && nodes.find(v2) != nodes.end()) {
        GraphNode* node1 = nodes[v1];
        GraphNode* node2 = nodes[v2];

        node1->neighbors.erase(
            std::remove(node1->neighbors.begin(), node1->neighbors.end(), node2),
            node1->neighbors.end()
        );

        node2->neighbors.erase(
            std::remove(node2->neighbors.begin(), node2->neighbors.end(), node1),
            node2->neighbors.end()
        );

        std::cout << "Edge between " << v1 << " and " << v2 << " removed.\n";
    } else {
        std::cout << "One or both vertices do not exist.\n";
    }
}

// Print the adjacency list representation of the graph
void Graph::display() {
    std::cout << "\nGraph Adjacency List:\n";
    for (const auto& pair : nodes) {
        std::cout << pair.first << ": ";
        for (auto neighbor : pair.second->neighbors) {
            std::cout << neighbor->value << " ";
        }
        std::cout << "\n";
    }
}

// Perform Breadth-First Search (BFS) traversal from the given starting vertex
void Graph::traverse(int startValue) {
    if (nodes.find(startValue) == nodes.end()) {
        std::cout << "Start vertex does not exist.\n";
        return;
    }

    std::map<int, bool> visited; // Track visited vertices
    std::queue<GraphNode*> q;    // Queue for BFS

    GraphNode* start = nodes[startValue];
    visited[start->value] = true;
    q.push(start);

    std::cout << "BFS Traversal starting at vertex " << startValue << ": ";

    while (!q.empty()) {
        GraphNode* current = q.front();
        q.pop();
        std::cout << current->value << " ";

        // Visit all unvisited neighbors
        for (GraphNode* neighbor : current->neighbors) {
            if (!visited[neighbor->value]) {
                visited[neighbor->value] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}

// Get BFS traversal as a string
std::string Graph::getTraversal(int startValue) {
    if (nodes.find(startValue) == nodes.end()) {
        return "Start vertex does not exist.";
    }

    std::string result = "";
    std::map<int, bool> visited;
    std::queue<GraphNode*> q;

    GraphNode* start = nodes[startValue];
    visited[start->value] = true;
    q.push(start);

    while (!q.empty()) {
        GraphNode* current = q.front();
        q.pop();
        result += std::to_string(current->value) + " ";

        for (GraphNode* neighbor : current->neighbors) {
            if (!visited[neighbor->value]) {
                visited[neighbor->value] = true;
                q.push(neighbor);
            }
        }
    }
    // Trim trailing space
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}
