class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size(),temp1,temp2=grid[m-1][n-1],i,j;
        k=k%(m*n);
        while(k--){
            temp2=grid[m-1][n-1];
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    temp1=grid[i][j];
                    grid[i][j]=temp2;
                    temp2=temp1;
                }
            }

        }
        return grid;
        
    }
};