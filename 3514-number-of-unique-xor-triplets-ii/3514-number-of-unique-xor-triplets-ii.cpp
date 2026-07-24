class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int B = 2048;

        bool seen[B] = {};
        bool two[B] = {};
        bool three[B] = {};

        vector<int> vals;

        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                vals.push_back(x);
            }
        }

        // All possible XORs of two values
        for (int a : vals) {
            for (int b : vals) {
                two[a ^ b] = true;
            }
        }

        // All possible XORs of three values
        for (int a : vals) {
            for (int x = 0; x < B; x++) {
                if (two[x]) {
                    three[a ^ x] = true;
                }
            }
        }

        return count(three, three + B, true);
    }
};