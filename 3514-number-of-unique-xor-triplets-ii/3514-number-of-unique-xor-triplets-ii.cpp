class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int B = 2048;

        vector<bool> one(B, false);
        for (int x : nums)
            one[x] = true;

        vector<bool> two(B, false);

        for (int a = 0; a < B; a++) {
            if (!one[a]) continue;

            for (int b = 0; b < B; b++) {
                if (one[b])
                    two[a ^ b] = true;
            }
        }

        vector<bool> three(B, false);

        for (int x = 0; x < B; x++) {
            if (!one[x]) continue;

            for (int y = 0; y < B; y++) {
                if (two[y])
                    three[x ^ y] = true;
            }
        }

        return count(three.begin(), three.end(), true);
    }
};