class Solution {
public:
    int sum(int num){
        int s=0;
        while(num>0){
            int r=num%10;
            s=s+r;
            num=num/10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sum(nums[i])==i){
                return i;
            }
        }
        return -1;
        
    }
};