class Solution {
public:
    void reverse(vector<vector<int>> &grid,int i,int j){
        int col=grid[0].size();
        while(i<j){
            int temp=grid[i/col][i%col];
            grid[i/col][i%col]=grid[j/col][j%col];
            grid[j/col][j%col]=temp;
            i++;
            j--;
        }

    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),temp1,temp2=grid[m-1][n-1],i,j;
        k=k%(m*n);
        reverse(grid,0,m*n-1);
        reverse(grid,0,k-1);
        reverse(grid,k,m*n-1);
        
        return grid;
        
    }
};