class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0,j=0,n=arr.size();
        long long currSum=0;
        vector<int> minLenTillIdx(n,INT_MAX);
        int result=INT_MAX;
        int bestMin=INT_MAX;
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i++];
            }
            if(currSum==target){
                int l=j-i+1;
                if(i>0 && minLenTillIdx[i-1]!=INT_MAX){
                    result=min(result,l+minLenTillIdx[i-1]);
                }
                bestMin=min(bestMin,l);
            }
            minLenTillIdx[j]=bestMin;
            j++;     
        }
        if(result==INT_MAX) return -1;
        return result;
        
    }
};