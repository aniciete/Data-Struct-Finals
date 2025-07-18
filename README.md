# Data Structures & Algorithms - Finals Project



```
 ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ▗▖   ▗▄▄▄▖ ▗▄▄▖ ▖▖    ▗▄▖ ▗▖  ▗▖ ▗▄▄▖▗▄▄▄▖▗▖   ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌   ▐▌    ▖    ▐▌ ▐▌▐▛▚▖▐▌▐▌   ▐▌   ▐▌   ▐▌
▐▌   ▐▛▀▜▌▐▛▀▜▌▐▛▀▚▖▐▌   ▐▛▀▀▘ ▝▀▚▖      ▐▛▀▜▌▐▌ ▝▜▌▐▌ ▜▌▐▛▀▀▘▐▌    ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘      ▐▌ ▐▌▐▌  ▐▌▝▚▄▞▘▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
```
<div align="center">

**A comprehensive C++ implementation of fundamental data structures and algorithms**

*Interactive • Educational • Performance-Focused*

[![C++](https://img.shields.io/badge/C%2B%2B-14-blue.svg)](https://isocpp.org/)
[![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)]()
[![License](https://img.shields.io/badge/license-Educational-orange.svg)]()

</div>

## Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Quick Start](#-quick-start)
- [Project Structure](#-project-structure)
- [Usage Guide](#-usage-guide)
- [Technical Specifications](#-technical-specifications)
- [Academic Information](#-academic-information)
- [Development Setup](#-development-setup)
- [Credits](#credits)

## Overview

This project is a modern, interactive C++ CLI application that demonstrates the implementation and practical usage of fundamental data structures and algorithms. Built as a finals project for the Data Structures and Algorithms course, it features a clean modular architecture, comprehensive error handling, and performance analysis tools.

### Key Highlights
- **Multiple Data Structures**: Stack, Queue, Binary Tree, Graph
- **Sorting Algorithms**: Bubble, Merge, Quick Sort
- **Performance Analysis**: Built-in timing for operations

## Features

This project implements the following data structures and algorithms from scratch:

### Data Structures

| Structure      | Implementation | Operations                                       |
| :------------- | :------------- | :----------------------------------------------- |
| **Stack**      | Static/Dynamic | `Push`, `Pop`, `Peek`, `isFull`, `isEmpty`         |
| **Queue**      | Static/Dynamic | `Enqueue`, `Dequeue`, `Peek`, `isFull`, `isEmpty`, `Size` |
| **Binary Tree**| Pointer-based  | `Insert`, `Delete`, `Search`, Traversal (In/Pre/Post-Order) |
| **Graph**      | Adjacency List | `Add/Remove Vertex`, `Add/Remove Edge`, Traversal (BFS) |

### Algorithms

| Category | Algorithm          | Description                                    |
| :------- | :----------------- | :--------------------------------------------- |
| Sorting  | **Bubble Sort**    | Simple `O(n²)` comparison-based algorithm.     |
|          | **Merge Sort**     | Efficient `O(n log n)` divide-and-conquer sort.|
|          | **Quick Sort**     | Fast `O(n log n)` average case sort.           |
| Traversal| **BFS**            | Breadth-First Search for graph traversal.      |
|          | **Tree Traversals**| In-Order, Pre-Order, and Post-Order traversals.|

## Quick Start

### Prerequisites

- **C++ Compiler**: g++ (GCC 4.9+ or Clang 3.4+)
- **Build Tool**: GNU Make
- **Git**: For repository cloning

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/aniciete/Data-Struct-Finals
   cd Data-Struct-Finals
   ```

2. **Build the project**
   ```bash
   make
   ```

3. **Run the application**
   ```bash
   ./DsaFinalProject
   ```

4. **Clean build files** (optional)
   ```bash
   make clean
   ```

### First Run

After launching, you'll see the main menu with options:

1. **Stack Operations** - Explore static and dynamic implementations
2. **Queue Operations** - FIFO data structure demonstrations
3. **Tree Operations** - Binary tree algorithms and traversals
4. **Graph Operations** - Graph algorithms and pathfinding
5. **Sorting Algorithms** - Compare sorting performance
6. **Exit Program** - Safe application termination

## Project Structure

```
Data-Struct-Finals/
├── main.cpp                 # Application entry point
├── Makefile                 # Build configuration
├── README.md               # This documentation
├── DsaFinalProject         # Compiled executable
└── src/
    ├── stack/              # Stack implementations
    │   ├── StaticStack.h/cpp   # Array-based stack
    │   ├── DynamicStack.h/cpp  # Linked list stack
    │   └── stackMenu.cpp       # Stack interface
    ├── queue/              # Queue implementations
    │   ├── StaticQueue.h/cpp   # Array-based queue
    │   ├── DynamicQueue.h/cpp  # Linked list queue
    │   └── queueMenu.cpp       # Queue interface
    ├── tree/               # Binary tree implementation
    │   ├── BinaryTree.h/cpp    # Tree data structure
    │   └── treeMenu.cpp        # Tree interface
    ├── graph/              # Graph implementation
    │   ├── Graph.h/cpp         # Graph data structure
    │   └── graphMenu.cpp       # Graph interface
    ├── sorting/            # Sorting algorithms
    │   ├── SortingAlgorithms.h/cpp
    │   └── sortingMenu.cpp     # Sorting interface
    └── utils/              # Utility functions
        ├── InputUtils.h/cpp    # Input validation
        ├── UIUtils.h/cpp       # User interface
        └── AsciiTitles.h/cpp   # ASCII art generation
```

## Usage Guide

After running the application, you will be greeted with the main menu. From here, you can navigate to different modules to interact with various data structures and algorithms.

### Example: Sorting Performance Analysis

1.  **Navigate**: From the main menu, select `Sort`.
2.  **Choose Algorithm**: Select an algorithm, for example, `Quick Sort`.
3.  **Select Data**: Choose the default array or provide a custom one.
4.  **View Results**: The program will display the original and sorted arrays, along with the time taken to perform the sort.

**Sample Output:**

```
Original array: [64, 34, 25, 12, 22, 11, 90]
Sorted array:   [11, 12, 22, 25, 34, 64, 90]
Time taken: 42 microseconds
```

> **Note**: The execution time is measured in microseconds and may vary depending on system load and hardware.

## Technical Specifications

- **Language**: C++14
- **Compiler**: g++ (MinGW on Windows, Clang on macOS)
- **Build System**: GNU Make
- **Core Features**:
  - Templated classes for generic data types (where applicable)

## Academic Information

### Course Details

| Field | Information |
|-------|-------------|
| **Course** | CCS0015L - Data Structures and Algorithms (Lab) |
| **Institution** | Far Eastern University Institute of Technology |
| **Schedule** | TB02 WED 10:00 - 12:50 |
| **Instructor** | Ronel F. Ramos, MIT |
| **Submission** | July 18, 2025 |
| **Project Type** | Finals Project |

## Development Setup

### For Windows Users

1. **Install MSYS2** from [msys2.org](https://www.msys2.org/)
2. **Install toolchain**:
   ```bash
   pacman -S --needed base-devel mingw-w64-x86_64-toolchain
   ```
3. **Add to PATH**: `C:\msys64\mingw64\bin`
4. **Install Git**: Download from [git-scm.com](https://git-scm.com/)

### For macOS Users

1. **Install Xcode Command Line Tools**:
   ```bash
   xcode-select --install
   ```

### For Linux Users

1. **Install build essentials**:
   ```bash
   sudo apt update
   sudo apt install build-essential git
   ```

### VS Code Extensions (Recommended)

- **C/C++ Extension Pack** (`ms-vscode.cpptools-extension-pack`)
- **Makefile Tools** (`ms-vscode.makefile-tools`)
- **GitLens** (`eamodio.gitlens`)

### Building and Testing

```bash
# Clean build
make clean && make

# Run with debugging
gdb ./DsaFinalProject

# Check for memory leaks (Linux/macOS)
valgrind --leak-check=full ./DsaFinalProject
```

## Contributing

This is an academic project for FEU Institute of Technology. For educational purposes:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## Credits

<div align="center">

| Member   | Primary Responsibility                                 |
| :------- | :----------------------------------------------------- |
| Aniciete | Static Stack, Dynamic Stack, Main Program Architecture |
| Buising  | Static Queue, Dynamic Queue                            |
| Einstein | Tree (Pre/Post/In Order Traversal)                     |
| Manaloto | Graph (Adjacency List)                                 |
| Manalo   | Sorting Algorithms (3 algorithms)                      |

</div>

## License

This project is created for educational purposes as part of the Data Structures and Algorithms course at Far Eastern University Institute of Technology.

---

<div align="center">

**Made with love for learning and education**

*FEU Institute of Technology • Data Structures & Algorithms • 2025*

</div>
