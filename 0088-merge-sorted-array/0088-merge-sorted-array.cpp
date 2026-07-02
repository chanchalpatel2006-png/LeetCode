class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n,p=m-1,q=n-1,i;
        if(m==0) {
            nums1=nums2;
            len=0;
        }
        for(i=len-1;q>=0 && i>=0;i--){
            if(nums1[p]>=nums2[q]){
                nums1[i]=nums1[p];
                nums1[p]=-1e9-1;
                p--;
                if(p<0) p=0;
            }
            else{
                nums1[i]=nums2[q];
                q--;
            }

        }
        

        
    }
};