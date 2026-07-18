class Solution {
public:
    void maxMin(vector<int> & nums,int i,int j ,int &Max,int &Min ){
        if(i==j){
            Max=nums[i];
            Min=nums[i];
        }
        else if(i+1==j){
            if(nums[i]>nums[j]){
                Max=nums[i];
                Min=nums[j];
            }
            else{
                Max=nums[j];
                Min=nums[i];
            }
        }
        else{
            int mid=i+(j-i)/2;
            int Max1,Min1;
            maxMin(nums,i,mid,Max,Min);
            maxMin(nums,mid+1,j,Max1,Min1);
            if(Max1>Max) Max=Max1;
            if(Min1<Min) Min=Min1;
        }
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int Max,Min;

        sort(nums.begin(),nums.end());
        maxMin(nums,0,n-1,Max,Min);
        return gcd(Max,Min);
        
    }
};