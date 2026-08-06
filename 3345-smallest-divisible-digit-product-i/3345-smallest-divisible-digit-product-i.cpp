class Solution {
public:
    int smallestNumber(int n, int t) {
        int r,d;
        for(int i=n;i<n+10;i++){
            r=i%10;
            if(!r) return i;
            d=(i/10==0)?1:i/10;
            if((r*d)%t==0){
                return i;
            } 
        }
        return 0; 
    }
};