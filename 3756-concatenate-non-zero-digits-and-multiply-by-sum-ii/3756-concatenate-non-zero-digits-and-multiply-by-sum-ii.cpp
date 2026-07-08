class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = queries.size();

        int len = s.size();

        vector<ll> sum(len, 0);

        vector<int> nonZeroCount(len, 0);

        vector<ll> P(len, 0), pow10(len + 1, 0);

        sum[0] = s[0] - '0';
        P[0] = s[0] - '0';
        pow10[0] = 1;
        nonZeroCount[0] = (s[0] == '0') ? 0 : 1;

        for (int i = 1; i < len; i++) {
            int digit = s[i] - '0';
            sum[i] = sum[i - 1] + digit;
        }


        for (int i = 1; i <= len; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        for (int i = 1; i < len; i++) {
            int digit = s[i] - '0';
            P[i] = P[i - 1];
            nonZeroCount[i] = nonZeroCount[i - 1];
            if (digit) {
                nonZeroCount[i]++;
                P[i] = (P[i - 1] * 10 + digit) % MOD;
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ll x = 0, Sum = 0, left = 0;
            int l = queries[i][0], r = queries[i][1];
            if (l != 0) {
                left = P[l - 1];
            }

            Sum = sum[r] - ((l == 0) ? 0 : sum[l - 1]);

            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l - 1]);
            x = (P[r] - (left * pow10[k])%MOD + MOD) % MOD;
            ans[i] = (int)(x%MOD * Sum%MOD) % MOD;
        }
        return ans;
    }
};