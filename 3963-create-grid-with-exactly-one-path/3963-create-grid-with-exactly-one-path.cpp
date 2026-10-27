class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string row;
        for(int i=0;i<n;i++){
            row.push_back('#');
        }
        for(int i=0;i<m;i++){
            ans.push_back(row);
        }
        for(int i=0;i<n;i++){
            ans[0][i]='.';
        }
        for(int i=0;i<m;i++){
            ans[i][n-1]='.';
        }
        return ans;
    }
};