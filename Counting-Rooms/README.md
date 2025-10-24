# Problem: Counting Rooms (CSES)
Problem link: https://cses.fi/problemset/task/1192

Given a grid of a building layout (`.` for floor, `#` for wall), this problem asks us to count the total number of distinct rooms. A room is any set of connected floor tiles.

## Approach

This is a classic graph traversal problem on a grid. Each room is a "connected component" of the graph. My goal is to iterate through the grid and, upon finding an unvisited floor tile, "flood-fill" the entire room it belongs to.

I chose to use **Depth-First Search (DFS)** for the flood-fill algorithm.

## Implementation

1.  **Grid & Visited Array:** I use a 2D array `a[][]` to store the grid (1 for floor, 0 for wall) and a 2D boolean array `ch[][]` (for "checked") to act as my `visited` array.
2.  **DFS Function:** My recursive DFS function `yes(x, y)` does the following:
    * Marks the current cell `(x, y)` as visited (`ch[x][y] = true`).
    * Recursively calls itself for all four adjacent neighbors (up, down, left, right) **only if** the neighbor is a floor tile (`a[...]==1`) and has not been visited (`ch[...]==0`).
3.  **Main Loop:**
    * I iterate through every cell `(i, j)` of the grid.
    * I check for two conditions:
        1.  Is the cell a floor? (`a[i][j] == 1`)
        2.  Have we *not* visited it yet? (`ch[i][j] == 0`)
    * If both are true, it means I've found a **new, undiscovered room**.
    * I then call my DFS function `yes(i, j)` to mark every tile in this new room as "visited".
    * After the DFS completes, I increment my `say` (room counter).

The final value of `say` is the total number of rooms.

## Complexity

* **Time Complexity:** $O(N \times M)$, where N and M are the dimensions of the grid. Every cell is visited exactly once by the main loop, and the DFS also visits each cell in a component at most once.
* **Space Complexity:** $O(N \times M)$ to store the grid and the `visited` array.
