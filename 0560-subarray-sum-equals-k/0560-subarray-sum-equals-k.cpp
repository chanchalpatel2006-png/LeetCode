class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        int l = 0, r = 0;
        vector<int> preSum(n, 0);
        map<int, int> mp;
        preSum[0] = nums[0];
        mp[0] = 1;
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        for (int i=0;i<n;i++) {
            int prefixSum = preSum[i];

            if (mp.find(prefixSum - k) != mp.end())
                count += mp[prefixSum - k];

            mp[prefixSum]++;
        }

        return count;
    }
};