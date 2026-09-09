class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    nums1[i]=j;
                    break;
                }
            }
        }
        int j=0;
        for (int x:nums1){
            for(int i=x+1;i<m;i++){
                if(nums2[x]<nums2[i]){
                    ans[j]=nums2[i];
                    break;
                }
            }
            j++;
        }
        return ans;


        
    }
};