class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=INT_MIN,mn=INT_MAX;
        vector<int> preMin(n,-1);
        for(int i=n-1;i>=0;i--){
            if(mn>nums[i]){
                preMin[i]=nums[i];
                mn=nums[i];
                continue;
            }
            preMin[i]=mn;
        }
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            mn=preMin[i];

            if(mx-mn<=k) return i;
        }
        return -1;

        
    }
};