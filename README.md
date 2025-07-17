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
