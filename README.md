
 ▗▄▄▖▗▖ ▗▖ ▗▄▖ ▗▄▄▖ ▗▖   ▗▄▄▄▖ ▗▄▄▖ ▖▖    ▗▄▖ ▗▖  ▗▖ ▗▄▄▖▗▄▄▄▖▗▖    ▗▄▄▖
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌   ▐▌    ▖    ▐▌ ▐▌▐▛▚▖▐▌▐▌   ▐▌   ▐▌   ▐▌   
▐▌   ▐▛▀▜▌▐▛▀▜▌▐▛▀▚▖▐▌   ▐▛▀▀▘ ▝▀▚▖      ▐▛▀▜▌▐▌ ▝▜▌▐▌▝▜▌▐▛▀▀▘▐▌    ▝▀▚▖
▝▚▄▄▖▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘      ▐▌ ▐▌▐▌  ▐▌▝▚▄▞▘▐▙▄▄▖▐▙▄▄▖▗▄▄▞▘
                                                                      
                                                                      
                                                                      

# Data Structures & Algorithms - Finals Project

A modern, modular, and user-friendly C++ CLI application demonstrating core data structures and algorithms. Features robust exception handling, performance timing, and a polished interactive experience.

## How to Run

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/your-username/Data-Struct-Finals.git
    cd Data-Struct-Finals
    ```

2.  **Compile the program:**
    ```bash
    make
    ```

3.  **Run the executable:**
    ```bash
    ./DsaFinalProject
    ```

## Course Details

- **Course:** Far Eastern University Institute of Technology - CCS0015L
- **Description:** Data Structures and Algorithms (Lab)
- **Schedule:** TB02 WED 10:00 - 12:50
- **Professor:** Ronel F. Ramos, MIT

The course covers the fundamentals of data structures and algorithms: concepts of abstract data; types of common data structures used; description, properties, and storage allocation of data structures, including lists and trees; algorithms for creating, updating, and manipulating data structures; relation between the running of an algorithm and the choice of data structures.

## Project Information

- **Project Type:** Finals Project
- **Submission Deadline:** July 18, 2025
- **Programming Language:** C++

### Project Requirements

Create a comprehensive C++ program implementing various data structures and algorithms with a unified main menu interface.

## Team Members & Primary Responsibilities

| Member     | Primary Responsibility                                |
| :--------- | :---------------------------------------------------- |
| Aniciete   | Static Stack, Dynamic Stack, Main Program Architecture |
| Buising    | Static Queue, Dynamic Queue                           |
| Einstein   | Tree (Pre/Post/In Order Traversal)                    |
| Manaloto   | Graph (Adjacency List)                                |
| Manalo     | Sorting Algorithms (3 algorithms)                     |

---

# Data Structures & Algorithms - Finals Project

A modern, modular, and user-friendly C++ CLI application demonstrating core data structures and algorithms. Features robust exception handling, performance timing, and a polished interactive experience.

---

## Features

- **Stacks:** Static and dynamic implementations
- **Queues:** Static and dynamic implementations
- **Binary Search Tree:** Insert, delete, search, and traversal
- **Graph:** Adjacency list, display
- **Sorting Algorithms:** Bubble, Merge, and Quick Sort with performance timing
- **Exception Handling:** Robust error management using C++ exceptions
- **Modular Design:** Each data structure's menu logic is in its own directory for maintainability
- **Polished CLI:**
  - Screen clears before every menu for a clean look
  - "Press Enter to continue..." prompt after every operation
  - Colorful, readable menus using ANSI codes

---

## Directory Structure

```
Data-Struct-Finals/
├── main.cpp
├── Makefile
├── README.md
├── src/
│   ├── stack/
│   │   ├── StaticStack.h/.cpp
│   │   ├── DynamicStack.h/.cpp
│   │   ├── stackMenu.h/.cpp
│   ├── queue/
│   │   ├── StaticQueue.h/.cpp
│   │   ├── DynamicQueue.h/.cpp
│   │   ├── queueMenu.h/.cpp
│   ├── tree/
│   │   ├── BinaryTree.h/.cpp
│   │   ├── treeMenu.h/.cpp
│   ├── graph/
│   │   ├── Graph.h/.cpp
│   │   ├── graphMenu.h/.cpp
│   ├── sorting/
│   │   ├── SortingAlgorithms.h/.cpp
│   │   ├── sortingMenu.h/.cpp
│   ├── utils/
│   │   ├── InputUtils.h/.cpp
│   │   ├── UIUtils.h/.cpp
```

---

## How to Build & Run

### **Using Make (Recommended for All Platforms)**

1. **Open a terminal in the project root.**
2. **Build the project:**
   ```bash
   make
   ```
3. **Run the program:**
   ```bash
   ./DsaFinalProject
   ```

### **Using Visual Studio Code**
- Open the folder in VS Code.
- Use the Run/Debug panel or Terminal as above.

---

## Usage Tips
- **Menus are modular:** Each data structure's menu is in its own folder for clarity and maintainability.
- **Screen is cleared** before every menu for a clean interface.
- **After every operation,** you'll see a "Press Enter to continue..." prompt so you never miss important output.
- **Invalid input is handled** gracefully with error messages.

---

## Contributing & Extending
- Add new features/algorithms by creating new `.h/.cpp` files in the appropriate `src/` subfolder.
- Add new menu logic in the same folder as the data structure.
- Update the `Makefile` to include new `.cpp` files.
- Follow the modular structure for easy collaboration and maintenance.

---

## Development Environment Setup

### **Windows**
- Install [MSYS2](https://www.msys2.org/) and the C++ toolchain (`pacman -S --needed base-devel mingw-w64-x86_64-toolchain`).
- Add `C:\msys64\mingw64\bin` to your PATH.
- Install Git for Windows.

### **macOS**
- Install Xcode Command Line Tools:
  ```bash
  xcode-select --install
  ```

### **VS Code Extensions (Recommended)**
- C/C++ Extension Pack (`ms-vscode.cpptools-extension-pack`)
- Makefile Tools (`ms-vscode.makefile-tools`)

---

## Authors & Credits
- Project modularized and polished for clarity, maintainability, and a professional CLI experience.
- Contributions welcome!
files:**
    ```bash
    # Example for the Queue developer
    git add src/queue/StaticQueue.h src/queue/StaticQueue.cpp
    ```

2.  **Commit with a meaningful message:**
    ```bash
    git commit -m "Feat: Implement enqueue and dequeue for StaticQueue"
    ```

3.  **Push your changes to the repository:**
    ```bash
    git push origin main
    ```

---

### **4. Development Environment Setup**

To ensure a consistent and effective development environment, every team member should follow these one-time setup steps for their operating system.

#### **For Windows Users**

The goal is to install `g++`, `make`, and `git`. The recommended way is via MSYS2.

1.  **Install MSYS2:** Download and run the installer from the [MSYS2 official website](https://www.msys2.org/). Follow the default installation steps.
2.  **Install C++ Toolchain:** Open the **MSYS2 MSYS** terminal from your Start Menu and run `pacman -Syu` to update. If it closes, reopen it and run it again. Then, install the tools:
    ```bash
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    ```
    Press Enter to select all packages when prompted.
3.  **Add to Windows PATH:** This is a critical step.
    *   Search for and open "Edit the system environment variables".
    *   Click "Environment Variables...", select the `Path` variable under "System variables", and click "Edit...".
    *   Click "New" and add the path to your MinGW bin folder. The default is `C:\msys64\mingw64\bin`.
    *   Click OK on all windows to save. Restart VS Code or your PC.
4.  **Install Git:** If you don't have it, download and install [Git for Windows](https://git-scm.com/download/win).

#### **For macOS Users**

1.  **Install Xcode Command Line Tools:** This single package contains `clang` (a C++ compiler), `make`, and `git`. Open the Terminal app and run:
    ```bash
    xcode-select --install
    ```
    Follow the prompts in the dialog box that appears.

#### **VS Code Extensions (For Everyone)**

1.  Open VS Code and go to the Extensions view (`Shift+Cmd+X` on Mac, `Ctrl+Shift+X` on Windows).
2.  Search for and install the following extensions:
    *   **C/C++ Extension Pack** (ID: `ms-vscode.cpptools-extension-pack`) - **Essential**.
    *   **Makefile Tools** (ID: `ms-vscode.makefile-tools`) - **Highly Recommended**.
