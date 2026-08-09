class Solution {
private:
    vector<vector<int>> dp;
    vector<int> suffixSum;

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n + 1, -1));

        suffixSum.resize(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }

        return dfs(0, 1, piles);
    }

private:
    int dfs(int i, int M, vector<int>& piles) {
        if (i == suffixSum.size()) return 0;
        if (dp[i][M] != -1) return dp[i][M];

        int res = 0;
        for (int X = 1; X <= 2 * M; X++) {
            if (i + X > suffixSum.size()) break;
            res = max(res, suffixSum[i] - dfs(i + X, max(M, X), piles));
        }

        return dp[i][M] = res;
    }
};