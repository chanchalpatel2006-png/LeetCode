class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),temp1,temp2=grid[m-1][n-1],i,j;
        k=k%(m*n);
        vector<int>nums;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                nums.push_back(grid[i][j]);
            }
        }
        rotate(nums.begin(), nums.end() - k, nums.end());
        int l=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                grid[i][j]=nums[l];
                l++;
            }
        }


        return grid;
        
    }
};