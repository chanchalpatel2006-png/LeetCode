class UnionFind {
public:
    vector<int> parent;  // Parent array for union-find structure
    int componentCount;  // Number of connected components

    // Initialize union-find with n elements
    UnionFind(int n) : componentCount(n), parent(n) {
        // Initially, each element is its own parent
        iota(parent.begin(), parent.end(), 0);
    }

    // Unite two elements, returns true if they were in different components
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Already in the same component
        if (rootA == rootB) {
            return false;
        }

        // Connect rootA to rootB
        parent[rootA] = rootB;
        componentCount--;
        return true;
    }

    // Find root of element x with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // If start or end position is a thief, no safe path exists
        if (grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }

        // BFS to calculate minimum distance from each cell to nearest thief
        queue<pair<int, int>> bfsQueue;
        int distance[n][n];
        memset(distance, 0x3f, sizeof(distance));  // Initialize with large value

        // Add all thief positions to queue as starting points
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {  // Found a thief
                    distance[row][col] = 0;
                    bfsQueue.emplace(row, col);
                }
            }
        }

        // Direction vectors for 4 adjacent cells (up, right, down, left)
        int directions[5] = {-1, 0, 1, 0, -1};

        // Multi-source BFS to calculate distances
        while (!bfsQueue.empty()) {
            auto [currentRow, currentCol] = bfsQueue.front();
            bfsQueue.pop();

            // Check all 4 adjacent cells
            for (int k = 0; k < 4; ++k) {
                int nextRow = currentRow + directions[k];
                int nextCol = currentCol + directions[k + 1];

                // Check bounds and if cell hasn't been visited
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < n &&
                    distance[nextRow][nextCol] == 0x3f3f3f3f) {

                    distance[nextRow][nextCol] = distance[currentRow][currentCol] + 1;
                    bfsQueue.emplace(nextRow, nextCol);
                }
            }
        }

        // Store all cells with their distance values
        vector<tuple<int, int, int>> cellsWithDistance;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cellsWithDistance.emplace_back(distance[row][col], row, col);
            }
        }

        // Sort cells by distance in descending order
        sort(cellsWithDistance.begin(), cellsWithDistance.end());
        reverse(cellsWithDistance.begin(), cellsWithDistance.end());

        // Use Union-Find to connect cells
        UnionFind uf(n * n);

        // Process cells from highest to lowest distance
        for (auto [currentDistance, row, col] : cellsWithDistance) {
            // Try to connect with adjacent cells that have distance >= currentDistance
            for (int k = 0; k < 4; ++k) {
                int adjacentRow = row + directions[k];
                int adjacentCol = col + directions[k + 1];

                // Check bounds and distance condition
                if (adjacentRow >= 0 && adjacentRow < n &&
                    adjacentCol >= 0 && adjacentCol < n &&
                    distance[adjacentRow][adjacentCol] >= currentDistance) {

                    // Connect current cell with adjacent cell
                    uf.unite(row * n + col, adjacentRow * n + adjacentCol);
                }
            }

            // Check if start and end are connected
            if (uf.find(0) == uf.find(n * n - 1)) {
                return currentDistance;  // Maximum safeness factor found
            }
        }

        return 0;  // No path exists
    }
};