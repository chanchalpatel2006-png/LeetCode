class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> arr;
        vector<vector<int>> components;
        vector<int> component;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int start = 0;
        for (int i = 0; i < n; i++) {

            component.push_back(arr[i][1]);

            if (i == n - 1 || arr[i + 1][0] - arr[i][0] > limit) {

                sort(component.begin(), component.end());
                components.push_back(component);

                component.clear();
            }
        }
        int idx = 0;
        for (auto x : components) {
            for (int y : x) {
                nums[y] = arr[idx][0];
                idx++;
            }
        }
        return nums;
    }
};