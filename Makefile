# Compiler to use
CXX = g++

# Compiler flags
# -std=c++11: Use the C++11 standard
# -Isrc:      Allows you to use #include "stack/StaticStack.h" instead of #include "src/stack/..."
# -g:         Include debugging information
# -Wall:      Turn on all warnings
CXXFLAGS = -std=c++11 -Isrc -g -Wall

# The final executable name
TARGET = DsaFinalProject

# List all your .cpp source files here
SRCS = main.cpp \
       src/stack/stackMenu.cpp \
       src/queue/queueMenu.cpp \
       src/stack/StaticStack.cpp \
       src/stack/DynamicStack.cpp \
       src/queue/StaticQueue.cpp \
       src/queue/DynamicQueue.cpp \
       src/tree/BinaryTree.cpp \
       src/graph/Graph.cpp \
       src/sorting/SortingAlgorithms.cpp \
       src/utils/InputUtils.cpp

# This is a rule that tells make how to create the final executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# A "clean" rule to delete the compiled files
clean:
	rm -f $(TARGET)

.PHONY: all clean