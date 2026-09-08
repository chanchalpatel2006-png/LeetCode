class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        
        int startColor=image[sr][sc];
        if(startColor==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        vector<pair<int,int>>neighbours={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;
            for(auto [deltaRow,deltaCol]:neighbours){
                int nrow=deltaRow+row;
                int ncol=deltaCol+col;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==startColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }

        }
        return image;
        
    }
};