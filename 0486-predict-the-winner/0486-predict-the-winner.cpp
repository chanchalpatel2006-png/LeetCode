class Solution {
public:
    int solve(vector<int>&nums,int i,int j){
        int take_i,take_j;
        if(i==j)return nums[i];
        if(i>j) return 0;
        take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        take_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return true;
        int sum=0,player1Score = 0, player2Score = 0;
        for(int value:nums){
            sum+=value;
        }

        player1Score=solve(nums,0,n-1);
        return sum-player1Score<=player1Score;
    }
};