#include "Graph.h"

/**
 * @brief Destructor for the Graph class.
 *
 * Iterates through all nodes in the graph and deletes them to free up memory.
 * This prevents memory leaks by ensuring all dynamically allocated GraphNode
 * objects are properly deallocated when the Graph object is destroyed.
 */
Graph::~Graph() {
    // Loop through each key-value pair in the nodes map
    for (auto& pair : nodes) {
        // Delete the GraphNode pointer to free memory
        delete pair.second;
    }
}

/**
 * @brief Adds a new vertex to the graph.
 *
 * Checks if a vertex with the given value already exists. If not, it creates a
 * new GraphNode and adds it to the nodes map.
 *
 * @param value The integer value for the new vertex.
 */
void Graph::addVertex(int value) {
    // Check if the vertex already exists in the graph
    if (nodes.find(value) == nodes.end()) {
        // If not, create a new node and add it to the map
        nodes[value] = new GraphNode(value);
        std::cout << "Vertex " << value << " added.\n";
    } else {
        // If it exists, notify the user
        std::cout << "Vertex already exists.\n";
    }
}

/**
 * @brief Adds an undirected edge between two vertices.
 *
 * Finds the nodes corresponding to the given values and adds each node to the
 * other's list of neighbors, creating an undirected edge. It also checks to
 * prevent adding duplicate edges.
 *
 * @param v1 The value of the first vertex.
 * @param v2 The value of the second vertex.
 */
void Graph::addEdge(int v1, int v2) {
    // Ensure both vertices exist in the graph
    if (nodes.find(v1) != nodes.end() && nodes.find(v2) != nodes.end()) {
        GraphNode* node1 = nodes[v1];
        GraphNode* node2 = nodes[v2];

        // Check if an edge already exists to avoid duplicates
        bool exists = false;
        for (auto neighbor : node1->neighbors) {
            if (neighbor->value == v2) {
                exists = true;
                break;
            }
        }

        // If no edge exists, add one
        if (!exists) {
            node1->neighbors.push_back(node2); // Add v2 to v1's neighbors
            node2->neighbors.push_back(node1); // Add v1 to v2's neighbors
            std::cout << "Edge added between " << v1 << " and " << v2 << ".\n";
        } else {
            std::cout << "Edge already exists.\n";
        }
    } else {
        // Notify if one or both vertices do not exist
        std::cout << "One or both vertices do not exist.\n";
    }
}

/**
 * @brief Removes a vertex and all its incident edges from the graph.
 *
 * Finds the specified vertex, removes all edges connecting to it from other
 * vertices, and then deletes the vertex itself.
 *
 * @param value The value of the vertex to remove.
 */
void Graph::removeVertex(int value) {
    auto it = nodes.find(value);
    // If vertex not found, do nothing
    if (it == nodes.end()) {
        std::cout << "Vertex does not exist.\n";
        return;
    }

    GraphNode* toRemove = it->second;

    // Iterate through all nodes to remove edges pointing to the vertex
    for (auto& pair : nodes) {
        GraphNode* node = pair.second;
        if (node != toRemove) {
            // Remove the specified vertex from the neighbor list
            node->neighbors.erase(
                std::remove(node->neighbors.begin(), node->neighbors.end(), toRemove),
                node->neighbors.end()
            );
        }
    }

    // Delete the vertex and remove it from the map
    delete toRemove;
    nodes.erase(it);
    std::cout << "Vertex " << value << " removed.\n";
}

/**
 * @brief Removes the edge between two specified vertices.
 *
 * If both vertices exist, this function removes the connection between them by
 * deleting each vertex from the other's adjacency list.
 *
 * @param v1 The value of the first vertex.
 * @param v2 The value of the second vertex.
 */
void Graph::removeEdge(int v1, int v2) {
    // Ensure both vertices exist
    if (nodes.find(v1) != nodes.end() && nodes.find(v2) != nodes.end()) {
        GraphNode* node1 = nodes[v1];
        GraphNode* node2 = nodes[v2];

        // Remove node2 from node1's neighbors
        node1->neighbors.erase(
            std::remove(node1->neighbors.begin(), node1->neighbors.end(), node2),
            node1->neighbors.end()
        );

        // Remove node1 from node2's neighbors
        node2->neighbors.erase(
            std::remove(node2->neighbors.begin(), node2->neighbors.end(), node1),
            node2->neighbors.end()
        );

        std::cout << "Edge between " << v1 << " and " << v2 << " removed.\n";
    } else {
        std::cout << "One or both vertices do not exist.\n";
    }
}

/**
 * @brief Displays the adjacency list representation of the graph.
 *
 * Iterates through each vertex in the graph and prints its value followed by
 * the values of all its neighbors. This provides a visual representation of
 * the graph's structure.
 */
void Graph::display() {
    std::cout << "\nGraph Adjacency List:\n";
    // Loop through each vertex in the graph
    for (const auto& pair : nodes) {
        std::cout << pair.first << ": ";
        // Print all neighbors of the current vertex
        for (auto neighbor : pair.second->neighbors) {
            std::cout << neighbor->value << " ";
        }
        std::cout << "\n";
    }
}

/**
 * @brief Performs a Breadth-First Search (BFS) traversal of the graph.
 *
 * Starts from a given vertex and explores all its neighbors at the present
 * depth prior to moving on to the vertices at the next depth level.
 *
 * @param startValue The value of the vertex to start the traversal from.
 */
void Graph::traverse(int startValue) {
    // Check if the starting vertex exists
    if (nodes.find(startValue) == nodes.end()) {
        std::cout << "Start vertex does not exist.\n";
        return;
    }

    std::map<int, bool> visited; // To keep track of visited vertices
    std::queue<GraphNode*> q;    // Queue for BFS

    // Start traversal from the given vertex
    GraphNode* start = nodes[startValue];
    visited[start->value] = true;
    q.push(start);

    std::cout << "BFS Traversal starting at vertex " << startValue << ": ";

    // Continue until the queue is empty
    while (!q.empty()) {
        GraphNode* current = q.front();
        q.pop();
        std::cout << current->value << " ";

        // Enqueue all unvisited neighbors
        for (GraphNode* neighbor : current->neighbors) {
            if (!visited[neighbor->value]) {
                visited[neighbor->value] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}

/**
 * @brief Returns the BFS traversal path as a string.
 *
 * Performs a BFS traversal starting from a given vertex and constructs a string
 * of the visited nodes in order.
 *
 * @param startValue The value of the vertex where traversal begins.
 * @return A string representing the BFS traversal path.
 */
std::string Graph::getTraversal(int startValue) {
    // Ensure the start vertex exists
    if (nodes.find(startValue) == nodes.end()) {
        return "Start vertex does not exist.";
    }

    std::string result = "";
    std::map<int, bool> visited;
    std::queue<GraphNode*> q;

    // Initialize BFS
    GraphNode* start = nodes[startValue];
    visited[start->value] = true;
    q.push(start);

    // Process the queue
    while (!q.empty()) {
        GraphNode* current = q.front();
        q.pop();
        result += std::to_string(current->value) + " ";

        // Add unvisited neighbors to the queue
        for (GraphNode* neighbor : current->neighbors) {
            if (!visited[neighbor->value]) {
                visited[neighbor->value] = true;
                q.push(neighbor);
            }
        }
    }

    // Remove the trailing space from the result string
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}
