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
        UIUtils::clearScreen(); // Clear the console for a fresh menu
        UIUtils::printSubMenu("Graph Menu", {"Add Vertex", "Add Edge", "Remove Vertex", "Remove Edge", "Display Graph", "Traverse Graph (BFS)", "Back to Main Menu"}); // Show menu options
        choice = getValidatedInput<int>("", 1, 7); // Get user choice (1-7)

        int v1, v2; // Variables for vertex input
        switch (choice) {
            case 1:
                // Add a new vertex to the graph
                v1 = getValidatedInput<int>("Enter vertex value: ");
                g.addVertex(v1);
                UIUtils::waitForEnter();
                break;
            case 2:
                // Add an edge between two vertices
                v1 = getValidatedInput<int>("Enter first vertex: ");
                v2 = getValidatedInput<int>("Enter second vertex: ");
                g.addEdge(v1, v2);
                UIUtils::waitForEnter();
                break;
            case 3:
                // Remove a vertex from the graph
                v1 = getValidatedInput<int>("Enter vertex to remove: ");
                g.removeVertex(v1);
                UIUtils::waitForEnter();
                break;
            case 4:
                // Remove an edge between two vertices
                v1 = getValidatedInput<int>("Enter first vertex of edge to remove: ");
                v2 = getValidatedInput<int>("Enter second vertex of edge to remove: ");
                g.removeEdge(v1, v2);
                UIUtils::waitForEnter();
                break;
            case 5:
                // Display the current graph structure
                g.display();
                UIUtils::waitForEnter();
                break;
            case 6:
                // Traverse the graph (BFS) from a starting vertex
                v1 = getValidatedInput<int>("Enter starting vertex for traversal: ");
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

