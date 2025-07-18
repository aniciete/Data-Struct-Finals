#include <iostream>
#include "graphMenu.h"
#include "Graph.h"
#include "../utils/UIUtils.h"
#include "../utils/InputUtils.h"

/**
 * @brief Manages the interactive menu for graph operations.
 *
 * This function initializes an empty graph and enters a loop to display a menu
 * of graph operations. It prompts the user for input and performs actions
 * such as adding/removing vertices and edges, displaying the graph, and
 * performing a BFS traversal based on the user's choice.
 */
void showGraphMenu() {
    Graph g; // Initialize an empty graph for operations.
    int choice; // Variable to store the user's menu selection.

    // Main loop to display the menu and handle user input.
    do {
        // Display the graph-specific submenu with available options.
        UIUtils::printSubMenu("Graph", {
            "Add Vertex", "Add Edge", "Remove Vertex", "Remove Edge",
            "Display Graph", "Traverse Graph (BFS)", "← Back"
        });
        // Get a validated integer input from the user.
        choice = InputUtils::getValidatedInput<int>("", 1, 7);

        int v1, v2; // Variables to store vertex values from user input.

        // Process the user's choice.
        switch (choice) {
            case 1: // Add Vertex
                v1 = InputUtils::getValidatedInput<int>("Enter vertex value to add: ");
                g.addVertex(v1);
                std::cout << UIUtils::GREEN << "Vertex added successfully." << UIUtils::RESET << std::endl;
                UIUtils::waitForEnter();
                break;
            case 2: // Add Edge
                v1 = InputUtils::getValidatedInput<int>("Enter first vertex for edge: ");
                v2 = InputUtils::getValidatedInput<int>("Enter second vertex for edge: ");
                g.addEdge(v1, v2);
                UIUtils::waitForEnter();
                break;
            case 3: // Remove Vertex
                v1 = InputUtils::getValidatedInput<int>("Enter vertex to remove: ");
                g.removeVertex(v1);
                UIUtils::waitForEnter();
                break;
            case 4: // Remove Edge
                v1 = InputUtils::getValidatedInput<int>("Enter first vertex of edge to remove: ");
                v2 = InputUtils::getValidatedInput<int>("Enter second vertex of edge to remove: ");
                g.removeEdge(v1, v2);
                UIUtils::waitForEnter();
                break;
            case 5: // Display Graph
                g.display();
                UIUtils::waitForEnter();
                break;
            case 6: // Traverse Graph (BFS)
                v1 = InputUtils::getValidatedInput<int>("Enter starting vertex for traversal: ");
                g.traverse(v1);
                UIUtils::waitForEnter();
                break;
            case 7: // Exit to the main menu.
                return;
            default: // Handle invalid input.
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7); // Continue until the user chooses to exit.
}