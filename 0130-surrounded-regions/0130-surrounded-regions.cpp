class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<pair<int,int>> neighbours={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int row=0;row<m;row++){
            if(board[row][0]=='O'){
                q.push({row,0});
                vis[row][0]=1;
            }
            if(board[row][n-1]=='O'){
                q.push({row,n-1});
                vis[row][n-1]=1;
            }
        }
        for(int col=0;col<n;col++){
            if(board[0][col]=='O' && !vis[0][col]){
                q.push({0,col});
                vis[0][col]=1;
            }
            if(board[m-1][col]=='O' && !vis[m-1][col]){
                q.push({m-1,col});
                vis[m-1][col]=1;
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto [drow,dcol]:neighbours){
                int nrow=drow+r;
                int ncol=dcol+c;
                if(ncol>=0 && nrow>=0 && ncol<n && nrow<m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='O' && !vis[row][col]){
                    board[row][col]='X';
                }
            }
        }      
    }
};