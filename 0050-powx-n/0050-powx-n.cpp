class Solution {
public:
    double myPow(double x, int n) {
        double ans=1,base=x;
        long long N=n;
        if(x==1) return x;
        if(x==-1) return (n%2)?-1:1;
        if(n<0){
           x=1/x;
           N=-N;
        }
        while(N>0){
            if(N&1){
                ans*=x;
            }
            x*=x;
            N>>=1;
            
        }
        
        return ans;
        
    }
};