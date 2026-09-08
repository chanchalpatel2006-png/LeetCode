class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> diff(n);
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=0;
        int count0=0,count1=0;
        for(int i=0;i<n;i++){
            if(nums[i]){
                count1++;
            }else{
                count0++;
            }
            diff[i]=count0-count1;
            if(mp.find(diff[i])!=mp.end()){
                ans=max(ans,i-mp[diff[i]]);
            }
            else mp[diff[i]]=i;
        }
        return ans;
    }
};