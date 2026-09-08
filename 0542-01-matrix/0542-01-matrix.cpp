class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==0){
                    q.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
        vector<pair<int,int>>neighbours={{0,1},{0,-1},{1,0},{-1,0}};
        int level=0;
        while(!q.empty()){
            level++;
            int sz=q.size();
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(auto [drow,dcol]:neighbours){
                    int nrow=drow+r;
                    int ncol=dcol+c;
                    if(ncol>=0 && ncol<n && nrow>=0 && nrow<m && !vis[nrow][ncol]){
                        mat[nrow][ncol]=level;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }

            }
        }
        return mat;
        
    }
};