#include "Graph.h"

void Graph::addVertex(int vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = std::vector<int>();
        std::cout << "Vertex " << vertex << " added.\n";
    } else {
        std::cout << "Vertex already exists.\n";
    }
}

void Graph::addEdge(int vertex1, int vertex2) {
    if (adjList.find(vertex1) != adjList.end() && adjList.find(vertex2) != adjList.end()) {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        std::cout << "Edge added between " << vertex1 << " and " << vertex2 << ".\n";
    } else {
        std::cout << "One or both vertices do not exist.\n";
    }
}

void Graph::removeVertex(int vertex) {
    if (adjList.find(vertex) != adjList.end()) {
        // Remove all edges to this vertex
        for (auto& pair : adjList) {
            auto& edges = pair.second;
            edges.erase(std::remove(edges.begin(), edges.end(), vertex), edges.end());
        }
        // Remove vertex itself
        adjList.erase(vertex);
        std::cout << "Vertex " << vertex << " removed.\n";
    } else {
        std::cout << "Vertex does not exist.\n";
    }
}

void Graph::removeEdge(int vertex1, int vertex2) {
    if (adjList.find(vertex1) != adjList.end() && adjList.find(vertex2) != adjList.end()) {
        auto& edges1 = adjList[vertex1];
        auto& edges2 = adjList[vertex2];
        edges1.erase(std::remove(edges1.begin(), edges1.end(), vertex2), edges1.end());
        edges2.erase(std::remove(edges2.begin(), edges2.end(), vertex1), edges2.end());
        std::cout << "Edge between " << vertex1 << " and " << vertex2 << " removed.\n";
    } else {
        std::cout << "One or both vertices do not exist.\n";
    }
}

void Graph::display() {
    std::cout << "\nGraph Adjacency List:\n";
    for (const auto& pair : adjList) {
        std::cout << pair.first << ": ";
        for (int neighbor : pair.second) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}

void Graph::traverse(int startVertex) {
    if (adjList.find(startVertex) == adjList.end()) {
        std::cout << "Start vertex does not exist.\n";
        return;
    }

    std::map<int, bool> visited;
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    std::cout << "BFS Traversal starting at vertex " << startVertex << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}
