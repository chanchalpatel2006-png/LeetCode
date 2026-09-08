class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> neighbours={{0,1},{-1,0},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int row=0;row<m;row++){
            if(grid[row][0]==1){
                grid[row][0]=0;
                q.push({row,0});
            }
            if(grid[row][n-1]==1){
                grid[row][n-1]=0;
                q.push({row,n-1});
            }
        }
        for(int col=0;col<n;col++){
            if(grid[0][col]==1){
                grid[0][col]=0;
                q.push({0,col});
            }
            if(grid[m-1][col]==1){
                grid[m-1][col]=0;
                q.push({m-1,col});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto [drow,dcol]:neighbours){
                int nrow=drow+r;
                int ncol=dcol+c;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=0;
                    q.push({nrow,ncol});
                }
            }
        }
        int ans=0;
        for(int row=1;row<m-1;row++){
            for(int col=1;col<n-1;col++){
                if(grid[row][col]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};