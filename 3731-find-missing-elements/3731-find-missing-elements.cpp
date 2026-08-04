class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> missing;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            int diff = nums[i] - (nums[i - 1]);
            if (diff > 1) {
                while (--diff) {
                    missing.push_back(nums[i - 1] + diff);
                }
            }
        }
        sort(missing.begin(),missing.end());
        return missing;
    }
};