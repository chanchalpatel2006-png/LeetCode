class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        unordered_map<int, int> rank;
        int r = 1;

        // Assign ranks to unique values
        for (int x : copy) {
            if (!rank.count(x))
                rank[x] = r++;
        }

        // Replace each element with its rank
        for (int &x : arr)
            x = rank[x];

        return arr;
    }
};