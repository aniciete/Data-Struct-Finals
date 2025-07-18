# Data Structures & Algorithms - Finals Project

<div align="center">

```
 ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ▗▖   ▗▄▄▄▖ ▗▄▄▖ ▖▖    ▗▄▖ ▗▖  ▗▖ ▗▄▄▖▗▄▄▄▖▗▖    ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌   ▐▌    ▖    ▐▌ ▐▌▐▛▚▖▐▌▐▌   ▐▌   ▐▌   ▐▌
▐▌   ▐▛▀▜▌▐▛▀▜▌▐▛▀▚▖▐▌   ▐▛▀▀▘ ▝▀▚▖      ▐▛▀▜▌▐▌ ▝▜▌▐▌ ▜▌▐▛▀▀▘▐▌    ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘      ▐▌ ▐▌▐▌  ▐▌▝▚▄▞▘▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
```

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

## Overview

This project is a modern, interactive C++ CLI application that demonstrates the implementation and practical usage of fundamental data structures and algorithms. Built as a finals project for the Data Structures and Algorithms course, it features a clean modular architecture, comprehensive error handling, and performance analysis tools.

### Key Highlights
- **Multiple Data Structures**: Stack, Queue, Binary Tree, Graph
- **Sorting Algorithms**: Bubble, Selection, Insertion, Merge, Quick Sort
- **Performance Analysis**: Built-in timing and complexity analysis
- **Interactive UI**: Clean CLI with ASCII art and colored output
- **Robust Design**: Comprehensive input validation and error handling

## Features

### Data Structures Implementation

| Structure | Static | Dynamic | Operations |
|-----------|--------|---------|------------|
| **Stack** | Yes | Yes | Push, Pop, Peek, Display, Size |
| **Queue** | Yes | Yes | Enqueue, Dequeue, Front, Rear, Display |
| **Binary Tree** | - | Yes | Insert, Delete, Search, Traversals |
| **Graph** | - | Yes | Add/Remove Vertices/Edges, DFS, BFS |

### Algorithm Implementations

- **Sorting Algorithms**
  - Bubble Sort (O(n²))
  - Selection Sort (O(n²))
  - Insertion Sort (O(n²))
  - Merge Sort (O(n log n))
  - Quick Sort (O(n log n) average)

- **Tree Algorithms**
  - Inorder, Preorder, Postorder Traversal
  - Search and Insert Operations
  - Tree Height Calculation

- **Graph Algorithms**
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Shortest Path Algorithms

### User Experience Features

- **ASCII Art Interface** - Beautiful command-line presentation
- **Performance Timing** - Real-time operation timing
- **Input Validation** - Comprehensive error checking
- **Visual Feedback** - Clear operation results and status
- **Interactive Menus** - Intuitive navigation system

## Quick Start

### Prerequisites

- **C++ Compiler**: g++ (GCC 4.9+ or Clang 3.4+)
- **Build Tool**: GNU Make
- **Git**: For repository cloning

### Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
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

### Navigation

The application uses a menu-driven interface:

- **Number Selection**: Enter the number corresponding to your choice
- **Input Validation**: Invalid inputs are caught and handled gracefully
- **Return Navigation**: Most menus allow returning to the previous level
- **Exit Options**: Safe exit available at any level

### Performance Analysis

Each operation includes timing information:

```
Operation completed in: 0.0023ms
Complexity: O(log n)
Elements processed: 1000
```

### Error Handling

The application provides clear feedback for:
- Invalid input types
- Out-of-range values
- Empty data structure operations
- Memory allocation failures

## Technical Specifications

### Build Configuration

- **Standard**: C++14
- **Compiler Flags**: `-std=c++14 -Isrc -g -Wall`
- **Include Path**: `src/` directory for modular includes
- **Debug Info**: Enabled with `-g` flag
- **Warnings**: All warnings enabled with `-Wall`

### Architecture

- **Design Pattern**: Modular architecture with clear separation
- **Memory Management**: RAII principles with proper cleanup
- **Error Handling**: Exception-safe operations throughout
- **Performance**: Optimized algorithms with timing analysis

### Dependencies

- **Standard Library**: `<iostream>`, `<vector>`, `<string>`, `<chrono>`
- **Custom Headers**: Modular components in `src/` directory
- **No External Libraries**: Pure C++ implementation

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

### Learning Objectives

- **Data Structure Implementation**: Hands-on coding of fundamental structures
- **Algorithm Analysis**: Understanding time and space complexity
- **Modular Programming**: Clean code organization and design patterns
- **Performance Optimization**: Efficient algorithm implementation
- **User Interface Design**: Creating intuitive command-line interfaces
- **Memory Management**: Proper allocation and deallocation practices

### Assessment Criteria

1. **Code Quality** (25%): Clean, readable, and well-documented code
2. **Functionality** (25%): Correct implementation of all requirements
3. **User Experience** (20%): Intuitive interface and error handling
4. **Performance** (15%): Efficient algorithms and optimization
5. **Documentation** (15%): Comprehensive README and code comments

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

## License

This project is created for educational purposes as part of the Data Structures and Algorithms course at Far Eastern University Institute of Technology.

---

<div align="center">

**Made with love for learning and education**

*FEU Institute of Technology • Data Structures & Algorithms • 2025*

</div>
