class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int Max=INT_MIN,length=0;
        int j=0;
        for(int i=0;i<n;i++){

            freq[nums[i]]++;
            if(freq[nums[i]]>k){
                while(nums[j]!=nums[i]){
                    freq[nums[j]]--;
                    j++;
                }
                freq[nums[j]]--;
                j++;
                length=i-j+1;
            }else{
                length++;
            }
            Max=max(Max,length);
        }
        return Max;
        
        
    }
};