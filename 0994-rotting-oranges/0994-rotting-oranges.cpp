class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), minute = 0;
        queue<pair<pair<int, int>,int>> q;
        int mx=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!vis[row][col] && grid[row][col] == 2) {
                    vis[row][col]=1;
                    q.push({{row, col}, 0});
                }
            }
        }

        vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t= q.front().second;
            q.pop();
            mx=max(mx,t);
            for (auto [dRow, dCol] : neighbours) {
                int nrow = dRow + r;
                int ncol = dCol + c;
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol},t+1});
                }
            }
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }

        return mx;
    }
};