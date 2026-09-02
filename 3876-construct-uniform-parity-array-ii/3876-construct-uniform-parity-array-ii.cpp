class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int smallestOdd=INT_MAX;
        for(int x:nums){
            if((x&1)==1){
                smallestOdd=min(smallestOdd,x);
            }
        }
        //trying for even numbers
        bool possible=true;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1 && nums[i]-smallestOdd<1){
                possible=false;
                break;
            }
        }
        if(possible) return true;
        possible=true;
        //trying for odd numbers
        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && nums[i]-smallestOdd<1){
                possible=false;
                break;
            }
        }
        return possible;

        
    }
};