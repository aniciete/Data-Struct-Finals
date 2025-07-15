# Data Structures & Algorithms - Finals Project

This document outlines the standard workflow for contributing to the Data Structures and Algorithms final project. Following this process will ensure smooth integration and minimize conflicts.

### **1. Project Status**

*   [x] Stack (Static & Dynamic)
*   [-] Queue (In Progress)
*   [ ] Tree
*   [ ] Graph
*   [ ] Sorting

### **2. How to Run the Project**

This project is configured to be built and run easily within Visual Studio Code.

1.  **Open the project in VS Code.**
2.  Go to the **Run and Debug** panel (the icon with a play button and a bug on the left-hand side).
3.  Click the green **"Start Debugging"** play button at the top of the panel.

This will automatically compile the entire project and launch the main program.

**Note on the `.vscode` directory:** We are intentionally committing the `.vscode` directory to the repository. It contains the `tasks.json` and `launch.json` files, which are essential for a consistent build and debug experience for all team members.

### **3. The Core Development Cycle**

This is the day-to-day workflow you will follow.

**Step 1: Sync with the Team**

Always start by pulling the latest changes from the repository to make sure you have the most up-to-date code from your teammates.

```bash
git pull origin main
```

**Step 2: Write Your Code**

Navigate to your assigned module directory (e.g., `src/queue/`) and implement your features in the `.h` and `.cpp` files.

**Step 3: Integrate and Test**

1.  **Add your files to the `Makefile`:** Open the `Makefile` in the root directory and add your new `.cpp` files to the `SRCS` list.
2.  **Run the project:** Use the "Run and Debug" button in VS Code to compile and run the entire project. This will test your changes in the context of the full application.

**Step 4: Commit and Push Your Code**

Once your local tests pass and the main build is not broken by your changes, commit your work.

1.  **Add your changed files:**
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
