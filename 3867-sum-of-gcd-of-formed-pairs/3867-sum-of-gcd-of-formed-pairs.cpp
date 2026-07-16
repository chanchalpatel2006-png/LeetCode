class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size(),mx=0,i;
        vector<int>prefixGcd(n);
        for(i=0;i<n;i++){
            mx=max(nums[i],mx);
            prefixGcd[i]=gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long sum=0;
        for(i=0;i<n/2;i++){
            sum+=gcd(prefixGcd[i],prefixGcd[n-i-1]);

        }
        return sum;

    }
};