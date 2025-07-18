#include "TestRunner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // For std::equal
#include <functional>

// Corrected include paths relative to the 'src' directory
#include "stack/StaticStack.h"
#include "stack/DynamicStack.h"
#include "queue/StaticQueue.h"
#include "queue/DynamicQueue.h"
#include "tree/BinaryTree.h"
#include "graph/Graph.h"
#include "sorting/SortingAlgorithms.h"
#include "utils/UIUtils.h"

// Helper to print test results in a standard format
void printTestResult(const std::string& testName, bool pass) {
    std::cout << testName << ": " << (pass ? "[PASS]" : "[FAIL]") << std::endl;
}

TestRunner::TestRunner(const std::string& testFilePath) : testFilePath(testFilePath) {}

void TestRunner::runTests() {
    UIUtils::clearScreen();
    std::cout << "--- Running All Automated Tests ---\n" << std::endl;
    runStackTests();
    std::cout << std::endl;
    runQueueTests();
    std::cout << std::endl;
    runTreeTests();
    std::cout << std::endl;
    runGraphTests();
    std::cout << std::endl;
    runSortingTests();
    std::cout << "\n--- All Tests Complete ---" << std::endl;
}

void TestRunner::runStackTests() {
    std::cout << "--- Running Stack Tests ---" << std::endl;

    // Test Static Stack
    StaticStack staticStack;
    // CORRECTED: Loop to push 100 elements to fill the stack completely.
    for (int i = 0; i < 100; ++i) {
        staticStack.push(i);
    }
    // Now the isFull() check should pass.
    printTestResult("Test Static Stack isFull", staticStack.isFull());

    bool overflow_passed = false;
    try {
        staticStack.push(100); // Attempt to push 101st element
    } catch (const std::runtime_error& e) {
        overflow_passed = (std::string(e.what()) == "Stack overflow");
    }
    printTestResult("Test Static Stack Overflow", overflow_passed);

    for (int i = 0; i < 100; ++i) staticStack.pop();
    printTestResult("Test Static Stack isEmpty", staticStack.isEmpty());
    
    bool underflow_passed = false;
    try {
        staticStack.pop();
    } catch (const std::runtime_error& e) {
        underflow_passed = (std::string(e.what()) == "Stack underflow");
    }
    printTestResult("Test Static Stack Underflow (pop)", underflow_passed);

    // Test Dynamic Stack
    DynamicStack dynamicStack;
    for (int i = 0; i < 1000; ++i) dynamicStack.push(i);
    
    bool push_pop_passed = true;
    for (int i = 999; i >= 0; --i) {
        if (dynamicStack.pop() != i) {
            push_pop_passed = false;
            break;
        }
    }
    printTestResult("Test Dynamic Stack Push/Pop 1000 elements", push_pop_passed && dynamicStack.isEmpty());

    underflow_passed = false;
    try {
        dynamicStack.pop();
    } catch (const std::runtime_error& e) {
        underflow_passed = (std::string(e.what()) == "Stack underflow");
    }
    printTestResult("Test Dynamic Stack Underflow (pop)", underflow_passed);
}

void TestRunner::runQueueTests() {
    std::cout << "--- Running Queue Tests ---" << std::endl;
    StaticQueue staticQueue;
    for(int i = 0; i < 100; ++i) staticQueue.enqueue(i);
    printTestResult("Test Static Queue isFull", staticQueue.isFull());
    bool full_passed = false;
    try {
        staticQueue.enqueue(100);
    } catch (const std::runtime_error& e) {
        full_passed = (std::string(e.what()) == "Queue is full");
    }
    printTestResult("Test Static Queue Enqueue when Full", full_passed);
    for(int i = 0; i < 100; ++i) staticQueue.dequeue();
    printTestResult("Test Static Queue isEmpty", staticQueue.isEmpty());
    bool empty_passed = false;
    try {
        staticQueue.dequeue();
    } catch (const std::runtime_error& e) {
        empty_passed = (std::string(e.what()) == "Queue is empty");
    }
    printTestResult("Test Static Queue Dequeue when Empty", empty_passed);
    DynamicQueue dynamicQueue;
    for (int i = 0; i < 1000; ++i) dynamicQueue.enqueue(i);
    bool all_match = true;
    for (int i = 0; i < 1000; ++i) {
        if (dynamicQueue.front() != i) {
            all_match = false;
            break;
        }
        dynamicQueue.dequeue();
    }
    printTestResult("Test Dynamic Queue Enqueue/Dequeue 1000 elements", all_match && dynamicQueue.isEmpty());
}

void TestRunner::runTreeTests() {
    std::cout << "--- Running Tree Tests ---" << std::endl;
    BinaryTree tree;
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(15);
    tree.insertNode(5);
    printTestResult("Test Tree Ignore Duplicate Insert", tree.getInOrderTraversal() == "5 10 15");
    tree.deleteNode(5);
    printTestResult("Test Tree Delete Leaf Node", tree.getInOrderTraversal() == "10 15");
    tree.insertNode(20);
    tree.insertNode(12);
    tree.deleteNode(15);
    printTestResult("Test Tree Delete Node with Two Children", tree.getInOrderTraversal() == "10 12 20");
    tree.deleteNode(10);
    printTestResult("Test Tree Delete Root Node", tree.getInOrderTraversal() == "12 20");
    printTestResult("Test Tree Search Non-existent Node", !tree.searchNode(99));
    printTestResult("Test Tree Search Existing Node", tree.searchNode(20));
}

void TestRunner::runGraphTests() {
    std::cout << "--- Running Graph Tests ---" << std::endl;
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    printTestResult("Test Graph BFS Traversal", g.getTraversal(1) == "1 2 3 4" || g.getTraversal(1) == "1 3 2 4");
    g.removeEdge(1, 3);
    printTestResult("Test Graph Remove Edge", g.getTraversal(1) == "1 2 4");
    g.removeVertex(2);
    printTestResult("Test Graph Remove Vertex", g.getTraversal(1) == "1");
    Graph disconnected;
    disconnected.addVertex(10);
    disconnected.addVertex(20);
    disconnected.addVertex(30);
    disconnected.addVertex(40);
    disconnected.addEdge(10, 20);
    disconnected.addEdge(30, 40);
    printTestResult("Test Disconnected Graph Traversal", disconnected.getTraversal(10) == "10 20");
}

void TestRunner::runSortingTests() {
    std::cout << "--- Running Sorting Tests ---" << std::endl;
    std::vector<int> empty = {};
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::vector<int> reverse_sorted = {5, 4, 3, 2, 1};
    std::vector<int> duplicates = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> expected_duplicates = {1, 1, 2, 3, 4, 5, 6, 9};
    auto test_algorithm = [&](const std::string& name, 
                              std::function<void(std::vector<int>::iterator, std::vector<int>::iterator)> sort_func) {
        std::vector<int> arr;
        arr = empty;
        sort_func(arr.begin(), arr.end());
        printTestResult(name + " - Empty Array", arr == empty);
        arr = sorted;
        sort_func(arr.begin(), arr.end());
        printTestResult(name + " - Sorted Array", arr == sorted);
        arr = reverse_sorted;
        sort_func(arr.begin(), arr.end());
        printTestResult(name + " - Reverse-Sorted Array", std::equal(arr.begin(), arr.end(), sorted.begin()));
        arr = duplicates;
        sort_func(arr.begin(), arr.end());
        printTestResult(name + " - Array with Duplicates", arr == expected_duplicates);
    };
    auto test_bubble = [&](const std::string& name) {
        std::vector<int> arr;
        arr = empty;
        SortingAlgorithms::bubbleSort(arr);
        printTestResult(name + " - Empty Array", arr == empty);
        arr = sorted;
        SortingAlgorithms::bubbleSort(arr);
        printTestResult(name + " - Sorted Array", arr == sorted);
        arr = reverse_sorted;
        SortingAlgorithms::bubbleSort(arr);
        printTestResult(name + " - Reverse-Sorted Array", std::equal(arr.begin(), arr.end(), sorted.begin()));
        arr = duplicates;
        SortingAlgorithms::bubbleSort(arr);
        printTestResult(name + " - Array with Duplicates", arr == expected_duplicates);
    };
    test_bubble("Bubble Sort");
    test_algorithm("Merge Sort", SortingAlgorithms::mergeSort<std::vector<int>::iterator>);
    test_algorithm("Quick Sort", SortingAlgorithms::quickSort<std::vector<int>::iterator>);
}