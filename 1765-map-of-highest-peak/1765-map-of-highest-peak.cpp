class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        vector<pair<int,int>> neighbours={{1,0},{-1,0},{0,-1},{0,1}};
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(isWater[row][col]==1){
                    result[row][col]=0;
                    q.push({{row,col},0});
                    vis[row][col]=1;
                }
                else{
                    result[row][col]=1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            for(auto [drow,dcol]:neighbours){
                int nrow=drow+r;
                int ncol=dcol+c;
                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    result[nrow][ncol]=steps+1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return result;

    }
};