class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),_xor=nums[0];
        int j=0;
        int nonZero=nums[0];
        for(int i=1;i<n;i++){
            _xor^=nums[i];
            if(nums[i]){
                nonZero=nums[i];
            }
        }
        if(nonZero==0){
            return 0;
        }else if(_xor==0){
            return n-1;
        }
        return n;
    }
};