class Solution {
public:
    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>>t;
    int getIntFromChar(char ch) { return (ch != 'S') ? ch - '0' : 0; }
    bool isValid(int i, int j, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }
    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E')
            return {0, 1};

        if (board[i][j] == 'X') {
            return {0, 0};
        }

        if(t[i][j]!=make_pair(-1,-1)){
            return t[i][j];
        }

        int upScore = 0, upPaths = 0;

        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];

        if (isValid(i - 1, j, board)) {
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0) {
                upScore += getIntFromChar(ch);
            }
        }
        if (isValid(i, j - 1, board)) {
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0) {
                leftScore += getIntFromChar(ch);
            }
        }
        if (isValid(i - 1, j - 1, board)) {
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0) {
                diagScore += getIntFromChar(ch);
            }
        }
        int bestScore = max({upScore, leftScore, diagScore});
        int bestPaths = 0;

        if (upScore == bestScore)
            bestPaths = (bestPaths + upPaths) % MOD;
        if (leftScore == bestScore)
            bestPaths = (bestPaths + leftPaths) % MOD;
        if (diagScore == bestScore)
            bestPaths = (bestPaths + diagPaths) % MOD;

        return t[i][j]={bestScore,bestPaths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        t.assign(n,vector<pair<int,int>> (n,{-1,-1}));
        pair<int, int> result = solve(n - 1, n - 1, board);

        return {result.first, result.second};
    }
};