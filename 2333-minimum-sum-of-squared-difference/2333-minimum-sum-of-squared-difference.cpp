class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k=k1+k2;
        int n=nums1.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
        }
        vector<int>diffCount(1e5+1,0);
        for(int x:diff){
            diffCount[x]++;
        }
        long long ans=0;
        for(int j=1e5;j>0 && k>0;j--){
            if (diffCount[j]==0) continue;
            if(diffCount[j]<=k){
                k=k-diffCount[j];
                diffCount[j-1]+=diffCount[j];
                diffCount[j]=0;
            }else{
                diffCount[j]-=k;
                diffCount[j-1]+=k;
                k=0;
            }
        }
        for(long long x=0;x<=1e5;x++){
            ans+=(diffCount[x]*x*x);
        }
        return ans;
        
    }
};