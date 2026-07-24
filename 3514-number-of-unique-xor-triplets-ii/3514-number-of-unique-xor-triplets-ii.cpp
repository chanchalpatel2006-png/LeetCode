class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> vals(nums.begin(), nums.end());
        unordered_set<int> xor2;
        unordered_set<int> xor3;

        // Unique XORs of two values
        for (int a : vals) {
            for (int b : vals) {
                xor2.insert(a ^ b);
            }
        }

        // Unique XORs of three values
        for (int a : vals) {
            for (int b : xor2) {
                xor3.insert(a ^ b);
            }
        }

        return xor3.size();
    }
};