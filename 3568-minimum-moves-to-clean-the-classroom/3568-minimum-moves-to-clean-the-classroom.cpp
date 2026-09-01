class state {
public:
    int r, c, e, mask;
};

int m, n;

class Solution {
public:
    bool safe(int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return false;
        }
        return true;
    }
    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size();
        n = classroom[0].size();
        int startRow, startCol;
        vector<vector<int>> litterPosBit(m, vector<int>(n));
        int postionBit = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } else if (classroom[r][c] == 'L') {
                    litterPosBit[r][c] = postionBit;
                    postionBit++;
                }
            }
        }
        int allCollected = (1 << postionBit) - 1;
        queue<state> q;
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        q.push({startRow, startCol, energy, 0});
        vector<vector<vector<vector<bool>>>> visited(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(energy+1,vector<bool>(allCollected+1))));
        int moves=0;
        visited[startRow][startCol][energy][0] = true;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                state curr = q.front();
                q.pop();
                if (curr.mask == allCollected) {
                    return moves;
                }
                if (curr.e == 0) {
                    continue;
                }
                for (auto dir : direction) {
                    int nextRow = curr.r + dir.first;
                    int nextCol = curr.c + dir.second;
                    if (!safe(nextRow, nextCol)) {
                        continue;
                    }
                    char cell = classroom[nextRow][nextCol];
                    if (cell == 'X') {
                        continue;
                    }
                    int nextEnergy = curr.e - 1;
                    int nextMask=curr.mask;
                    if (cell == 'R') {
                        nextEnergy = energy;
                    }
                    if (cell == 'L') {
                        int p = litterPosBit[nextRow][nextCol];
                        nextMask = curr.mask | (1 << p);
                    }
                    if (visited[nextRow][nextCol][nextEnergy][nextMask] ==
                        false) {
                        visited[nextRow][nextCol][nextEnergy][nextMask] = true;
                        q.push({nextRow, nextCol, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};