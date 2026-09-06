class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int maxProd=1;
        for(int x:nums){
            if(x==0){
                zero++;
            }
            else{
                maxProd*=x;
            }
        }
        vector<int> result(n,0);
        if(zero>1){
            return result;
        }
        else if(zero==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    result[i]=maxProd;
                }
                else{
                    result[i]=0;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                result[i]=maxProd/nums[i];
            }
        }
        return result;
    }
};