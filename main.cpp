#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <chrono>
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"
#include "utils/InputUtils.h"
#include "utils/UIUtils.h"
#include "utils/AsciiTitles.h"
#include "stack/stackMenu.h"
#include "queue/queueMenu.h"
#include "tree/treeMenu.h"
#include "graph/graphMenu.h"
#include "sorting/sortingMenu.h"

void showMainMenu();
void showSplashScreen();

int main() {
    int choice;
    showSplashScreen();

    do {
        showMainMenu();
        choice = InputUtils::getValidatedInput<int>("", 1, 7);

        switch (choice) {
            case 1: showStackMenu(); break;
            case 2: showQueueMenu(); break;
            case 3: showTreeMenu(); break;
            case 4: showGraphMenu(); break;
            case 5: showSortingMenu(); break;
            case 6: {
                char confirm = InputUtils::getValidatedInput("Are you sure you want to exit? (y/n): ", {'y', 'n'});
                if (confirm == 'y') {
                    std::cout << "Exiting program. Goodbye!\n";
                    return 0;
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
        std::cout << "\n";
    } while (true);

    return 0;
}

void showMainMenu() {
    UIUtils::clearScreen();
    UIUtils::printTitle("Main");
    UIUtils::printMenu({
        "Stack Operations",
        "Queue Operations",
        "Tree Operations",
        "Graph Operations",
        "Sorting Algorithms",
        "Exit Program",
    });
}

void showSplashScreen() {
    UIUtils::clearScreen();
    UIUtils::printTitle("Welcome");
    UIUtils::waitForEnter();
}