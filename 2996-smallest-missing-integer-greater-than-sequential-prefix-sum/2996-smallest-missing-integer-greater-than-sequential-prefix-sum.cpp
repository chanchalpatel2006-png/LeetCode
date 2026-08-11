class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find the sequential prefix sum
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Put all numbers in a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest integer >= sum that is missing
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};