class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> adj(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int node = (i * n) + (j);
                if (grid[i][j] == '1') {
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                        adj[node].push_back(node - n);
                        adj[node - n].push_back(node);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                        adj[node].push_back(node - 1);
                        adj[node - 1].push_back(node);
                    }
                }
            }
        }
        vector<int> vis(m * n, 0);
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]=='0') continue;
                if (vis[i*n+j])
                    continue;
                islands++;
                
                queue<int> q;
                q.push(i*n+j);
                vis[i*n+j] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : adj[node]) {
                        if (vis[it])
                            continue;
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return islands;
    }
};