class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,1);
        int suffix=nums[n-1];
        for(int i=1;i<n;i++){
            result[i]=nums[i-1]*result[i-1];
        }
        for(int i=n-2;i>=0;i--){
            result[i]*=suffix;
            suffix*=nums[i];
        }
        return result;
    }
};