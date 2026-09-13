class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        int c;
        for(int row_offset=-n+1;row_offset<n;row_offset++){
            for(int col_offset=-n+1;col_offset<n;col_offset++){
                c=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int row=i+row_offset;
                        int col=j+col_offset;
                        if(row<n && col<n && row>=0 && col >=0){
                            c=c+(img1[i][j]&img2[row][col]);
                        }
                    }
                }
                ans=max(ans,c);
            }

        }
        return ans;
        
    }
};