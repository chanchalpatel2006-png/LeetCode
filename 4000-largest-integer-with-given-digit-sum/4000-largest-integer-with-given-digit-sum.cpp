class Solution {
public:
    int largestInteger(int n, int s) {
        int largest=(int)pow(10,n)-1;
        int largestSum=9*n;
        if(s==0) return 0;
        int ans=0;
        if(largestSum<s) return -1;
        while(s>0){
            int digit=min(9,s);
            ans=ans*10+digit;
            s=s-digit;
        }
        while(ans*10<largest){
            ans=ans*10;
        }
        return ans;

        
    }
};