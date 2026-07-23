class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return n;
        int base=2;
        while(base<=n){
            base=base<<1;
        }
        return base;   
    }
};