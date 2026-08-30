class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size(),minIdx=0,maxIdx=0;
        for(int i=1;i<n;i++){
            if(nums[minIdx]>nums[i]){
                minIdx=i;
            }
            if(nums[maxIdx]<nums[i]){
                maxIdx=i;
            }
        }
        int a=max(minIdx,maxIdx);
        a++;
        int b=min(minIdx,maxIdx);
        b=n-b;
        int c=0;
        if(minIdx<=n/2){
            c=c+minIdx+1;
        }
        else{
            c=c+n-minIdx;
        }
        if(maxIdx<=n/2){
            c+=maxIdx+1;
        }
        else{
            c+=n-maxIdx;
        }
        return min({a,b,c});
        
    }
};