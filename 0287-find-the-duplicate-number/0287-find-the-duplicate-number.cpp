class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int c=0,i=0,j=0;
        while(c<=n){
            if(i==nums[i]-1) {
                i++;
                continue;
            }
            if((nums[i]^nums[nums[i]-1])==0){
                return nums[i];
            }
            swap(nums[i],nums[nums[i]-1]);
            c++;
 
        }
        return 0;
        
    }
};