class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int base=1;
        int mx=*max_element(nums.begin(),nums.end());
        while(base<=mx){
            base=base<<1;
        }
        vector<bool> xor2(base,false);
        vector<bool> xor3(base,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xor2[nums[i]^nums[j]]=true;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<base;j++){
                if(xor2[j]){
                    xor3[nums[i]^j]=true;
                }
            }
        }


        return count(xor3.begin(),xor3.end(),true);
        
    }
};