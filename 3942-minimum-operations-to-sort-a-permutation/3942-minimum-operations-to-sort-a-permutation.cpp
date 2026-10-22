class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return 0;
        int left=0;
        int ans=0;
        int start,end;
        for(int i=0;i<n;i++){
            int next = (i + 1) % n;
            int prev = (i + n - 1) % n;
            if(nums[i]==n-1){
                end=i;
                if(nums[next]==0 && nums[prev]==n-2){
                    left=1;
                }
                else if(nums[prev]==0 && nums[next]==n-2){
                    left=0;
                }
                else{
                    return -1;
                }
            }
            else if(nums[i]==0){
                start=i;
                if (!((nums[next]==1 && nums[prev]==n-1) 
                || (nums[next]==n-1 && nums[prev]==1) ))
                {
                    return -1;
                }
            }
            else{
                if(!((nums[next]==nums[i]+1 && nums[prev]==nums[i]-1) 
                || (nums[next]==nums[i]-1 && nums[prev]==nums[i]+1)))
                {
                    return -1;
                }
            }
        }
        if(left){
                return min(start, n - start + 2);
            }
            else{
                int k = (n - 1 - start + n) % n;
                return 1 + min(k, (n - k) % n);
            }
        return ans;
        
    }
};