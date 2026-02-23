📖 Project Overview

This project implements an iterative Depth-First Search (DFS) traversal on a graph stored as an adjacency matrix, and prints the spanning tree edges discovered during traversal (also called a coverage tree / spanning tree for the visited component).

The traversal starts from a user-chosen root node. If the graph is not fully reachable from that root, the program asks for a new root and repeats until all nodes are visited.

🧠 Core Idea

The graph is represented as an adjacency matrix (graf[i][j] = 1 means an edge exists).

DFS is implemented using an explicit stack (not recursion for traversal).

Each time we move to an unvisited neighbor, we output the edge (parent, child) — that edge becomes part of the spanning tree.

✅ What the Program Does
DFS Traversal

Starts from a chosen root node

Visits nodes using DFS (stack-based)

Marks visited nodes in a vizitat[] array

Spanning Tree Output

Prints the edges used to reach each newly discovered node:

(u, v) means the DFS tree includes edge u → v

Connectivity Check

After traversal, it checks if all nodes were visited

If not, it prompts for another root and re-runs traversal

🏗️ Project Structure
.
├── main.c
└── README.md
