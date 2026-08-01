class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Initialize variables with the first element
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int current = nums[i];
            if (current < 0) {
                swap(max_so_far, min_so_far);
            }
            max_so_far = max(current, max_so_far * current);
            min_so_far = min(current, min_so_far * current);
            result = max(result, max_so_far);
        }

        return result;
        
    }
};