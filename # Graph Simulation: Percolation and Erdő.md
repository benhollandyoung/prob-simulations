# Graph Simulation: Percolation and Erdős–Rényi Models

This project contains C++ implementations of two fundamental random graph models:

### 🔷 Bond Percolation
Simulates bond percolation on an _n × n_ grid. Edges between neighboring grid points are added with a given probability `p`. The result is a random subgraph of the grid, representing possible percolation paths.

### 🔷 Erdős–Rényi Graph
Generates a random graph with `n` nodes where each possible edge is added independently with probability `p`, following the Erdős–Rényi (G(n, p)) model.

### 🔍 Visualization
Each simulation outputs its edge list to a CSV or text file. A Python script using `matplotlib` is provided to visualize the resulting graph.

### 💻 Requirements
- C++17-compatible compiler (e.g. `g++`, `clang++`)
- Python 3 with `matplotlib` installed

### 🏃‍♂️ How to Use
1. Compile the C++ code using your preferred compiler.
2. Run the program and enter parameters when prompted.
3. The program will generate a graph and write it to a file.
4. Use the included Python script (`draw_graph.py`) to visualize the graph.

