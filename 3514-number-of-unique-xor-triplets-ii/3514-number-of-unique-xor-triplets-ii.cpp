class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int B = 2048;

        bool seen[B] = {};
        bool two[B] = {};
        bool three[B] = {};

        vector<int> vals;
        vector<int> pairs;

        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                vals.push_back(x);
            }
        }

        for (int a : vals) {
            for (int b : vals) {
                int x = a ^ b;

                if (!two[x]) {
                    two[x] = true;
                    pairs.push_back(x);
                }
            }
        }

        for (int a : vals) {
            for (int x : pairs) {
                three[a ^ x] = true;
            }
        }

        return count(three, three + B, true);
    }
};