# Leetcode-1584.-Min-Cost-to-Connect-All-Points
# 🧲 Minimum Cost to Connect All Points (Prim’s Algorithm) – C++

This repository contains an optimized C++ implementation for solving the **"Minimum Cost to Connect All Points"** problem using **Prim’s Algorithm** with a **priority queue (min-heap)**. The goal is to connect all 2D points with the **minimum total cost**, where cost is measured via **Manhattan distance**.
---
## 📌 Problem Description

You are given an array `points` representing coordinates of points on a 2D plane. The cost to connect two points is the **Manhattan distance** between them. Return the **minimum total cost** to connect all points such that there's **exactly one simple path** between any two points (i.e., a **Minimum Spanning Tree**).

---

## 🧠 Algorithm Overview

- **Graph Construction**: Create a **complete graph** where each node is a point and each edge is the Manhattan distance.
- **MST Construction**: Use **Prim’s Algorithm** to construct a Minimum Spanning Tree by:
  - Starting from a node (point 0),
  - Using a **min-heap (priority queue)** to greedily pick the smallest edge,
  - Expanding the MST by adding unvisited nodes.

---

## 🧾 Input Format

- `points`: A vector of size `n` where each element is a vector `[x, y]`.

---

## 📤 Output

- Returns a single integer: **minimum total cost** to connect all points.

---

## ✅ Example Usage


vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
Solution sol;
int result = sol.minCostConnectPoints(points);
cout << "Minimum cost: " << result << endl; // Output: 20


📊 Time & Space Complexity
Time Complexity: O(n² log n)


Building the complete graph: O(n²)
Prim’s algorithm (with min-heap): O(n log n²) ≈ O(n² log n)
Space Complexity: O(n²) for storing all edge weights


🔧 Techniques Used
Manhattan distance: abs(x1 - x2) + abs(y1 - y2)
Priority Queue (Min Heap)
Graph construction
Prim's MST algorithm


👨‍💻 Author
Your Name – @irythmgarg [Ridham Garg]


