class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = -1;
        if (n == k)
            return *max_element(nums.begin(), nums.end());
        vector<int> hash(51, 0);
        for (int x : nums) {
            hash[x]++;
        }
        

        if (k == 1) {
            for (int x : nums) {
                if (hash[x] == 1) {
                    mx = max(mx, x);
                }
            }
            return mx;
        }
        if (hash[nums[0]] == 1) {
            mx = max(mx, nums[0]);
        }
        if (hash[nums[n - 1]] == 1) {
            mx = max(mx, nums[n - 1]);
        }

        return mx;
    }
};