class Solution {
public:
    int maxProduct(int n) {
        int first=0,second=0;
        while(n>0){
            int r=n%10;
            n/=10;
            if(r>second){
                first=second;
                second=r;
            }
            else if(r>first){
                first=r;
            }

        }
        return first*second;
        
    }
};