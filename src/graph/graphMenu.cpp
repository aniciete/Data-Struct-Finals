#include <iostream>
#include "graphMenu.h"
#include "Graph.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

// Display and handle the Graph menu for user interaction
void showGraphMenu() {
    Graph g; // Start with an empty graph
    int choice;
    do {
        
        // CORRECTED: Changed title to "Graph" to match the ASCII art key
        UIUtils::printSubMenu("Graph", {"Add Vertex", "Add Edge", "Remove Vertex", "Remove Edge", "Display Graph", "Traverse Graph (BFS)", "← Back"}); // Show menu options
        choice = InputUtils::getValidatedInput<int>("", 1, 7); // Get user choice (1-7)

        int v1, v2; // Variables for vertex input
        switch (choice) {
            case 1:
                // Add a new vertex to the graph
                v1 = InputUtils::getValidatedInput<int>("Enter vertex value to add: ");
                g.addVertex(v1);
                std::cout << UIUtils::GREEN << "Vertex added successfully." << UIUtils::RESET << std::endl;
                UIUtils::waitForEnter();
                break;
            case 2:
                // Add an edge between two vertices
                v1 = InputUtils::getValidatedInput<int>("Enter first vertex for edge: ");
                v2 = InputUtils::getValidatedInput<int>("Enter second vertex for edge: ");
                g.addEdge(v1, v2);
                // Note: Add edge success/failure is not yet implemented in Graph.cpp
                UIUtils::waitForEnter();
                break;
            case 3:
                // Remove a vertex from the graph
                v1 = InputUtils::getValidatedInput<int>("Enter vertex to remove: ");
                g.removeVertex(v1);
                // Note: Remove vertex success/failure is not yet implemented in Graph.cpp
                UIUtils::waitForEnter();
                break;
            case 4:
                // Remove an edge between two vertices
                v1 = InputUtils::getValidatedInput<int>("Enter first vertex of edge to remove: ");
                v2 = InputUtils::getValidatedInput<int>("Enter second vertex of edge to remove: ");
                g.removeEdge(v1, v2);
                // Note: Remove edge success/failure is not yet implemented in Graph.cpp
                UIUtils::waitForEnter();
                break;
            case 5:
                // Display the current graph structure
                g.display();
                UIUtils::waitForEnter();
                break;
            case 6:
                // Traverse the graph (BFS) from a starting vertex
                v1 = InputUtils::getValidatedInput<int>("Enter starting vertex for traversal: ");
                g.traverse(v1);
                UIUtils::waitForEnter();
                break;
            case 7:
                // Go back to the main menu
                return;
            default:
                // Handle invalid menu choices
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7); // Repeat until user chooses to go back
}