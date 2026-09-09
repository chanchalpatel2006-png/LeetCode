class Solution {
public:
    int largestInteger(int n, int s) {
        int largest=(int)pow(10,n)-1;
        int largestSum=9*n;
        if(s==0) return 0;
        int ans=0;
        if(largestSum<s) return -1;
        while(s>0){
            for(int i=9;i>0;i--){
                if(i<=s){
                    ans=ans*10+i;
                    s-=i;
                    break;
                }
            }
        }
        while(ans*10<largest){
            ans=ans*10;
        }
        return ans;

        
    }
};