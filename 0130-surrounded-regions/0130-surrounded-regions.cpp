class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<pair<int,int>> neighbours={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int row=0;row<m;row++){
            if(board[row][0]=='O'){
                q.push({row,0});
                board[row][0]='#';
            }
            if(board[row][n-1]=='O'){
                q.push({row,n-1});
                board[row][n-1]='#';
            }
        }
        for(int col=0;col<n;col++){
            if(board[0][col]=='O'){
                q.push({0,col});
                board[0][col]='#';
            }
            if(board[m-1][col]=='O'){
                q.push({m-1,col});
                board[m-1][col]='#';
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto [drow,dcol]:neighbours){
                int nrow=drow+r;
                int ncol=dcol+c;
                if(ncol>=0 && nrow>=0 && ncol<n && nrow<m && board[nrow][ncol]=='O'){
                    board[nrow][ncol]='#';
                    q.push({nrow,ncol});
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='O'){
                    board[row][col]='X';
                }
                if(board[row][col]=='#'){
                    board[row][col]='O';
                }

            }
        }      
    }
};