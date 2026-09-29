class Solution {
public:
    int t[101][101][201];
    bool solve(int r,int c,int count,vector<vector<char>> & grid){
        int m=grid.size(),n=grid[0].size();
        if(r>=m || c>=n){
            return false;
        }
        if(grid[r][c]=='('){
            count++;
        }
        else if(grid[r][c]==')' && count>0){
            count--;
        }
        else return false;
        if(t[r][c][count]!=-1){
            return t[r][c][count];
        }
        if(r==m-1 && c==n-1 && count==0){
            return true;
        }
        
        bool down=solve(r+1,c,count,grid);
        bool right=solve(r,c+1,count,grid);
        return t[r][c][count]=(down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(t,-1,sizeof(t));
        int m=grid.size(),n=grid[0].size();
        if((m+n-1)%2) return false;
        return solve(0,0,0,grid); 
    }
};