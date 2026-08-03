class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> temp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            temp[i] = stoneValue[i] - temp[i + 1];
            if (i + 2 <= n) {
                temp[i] = max(temp[i],
                              stoneValue[i] + stoneValue[i + 1] - temp[i + 2]);
            }
            if (i + 3 <= n) {
                temp[i] = max(temp[i], stoneValue[i] + stoneValue[i + 1] +
                                           stoneValue[i + 2] - temp[i + 3]);
            }
        }
        if (temp[0] > 0) {
            return "Alice";
        } else if (temp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};