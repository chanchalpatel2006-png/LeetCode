class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;   // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // next non-overlapping interval
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Don't take i
                State skip = dp[i + 1][k];

                // Take i
                State take = dp[nxt[i]][k - 1];

                take.score += a[i][2];
                take.ids.push_back(a[i][3]);

                // IDs are currently in selection order.
                sort(take.ids.begin(), take.ids.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};