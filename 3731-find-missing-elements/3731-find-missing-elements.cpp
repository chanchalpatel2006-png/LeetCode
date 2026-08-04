class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> missing;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            for(int j=nums[i-1]+1;j<nums[i];j++) {
                missing.push_back(j);
            }
        }
        return missing;
    }
};