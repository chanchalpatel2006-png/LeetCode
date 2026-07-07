class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0,sum=0,r;
        while(n>0){
            r=n%10;
            if(r!=0){
                x=(x*10)+(r);
                sum+=r;
            }
            n=n/10;
        }
        n=0;
        while(x>0){
            r=x%10;
            n=n*10+r;
            x/=10;
        }
        return n*sum;
    }
};