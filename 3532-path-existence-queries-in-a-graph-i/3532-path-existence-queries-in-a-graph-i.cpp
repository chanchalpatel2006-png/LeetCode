class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<bool> ans(q);
        vector<int> component(n);
        component[0] = 0;
        for (int i = 1; i < n; i++) {
            component[i] = component[i - 1];
            if (abs(nums[i] - nums[i - 1]) > maxDiff) {
                component[i]++;
            }
        }
        for (int i = 0; i < q; i++) {
            if (component[queries[i][0]] == component[queries[i][1]]) {
                ans[i]=true;
            } else {
                ans[i]=false;
            }
        }
        return ans;
    }
};