class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int firstRowZero=0;
        int firstColZero=0;
        int i,j;
        for(i=0;i<m;i++){
            if(!matrix[i][0]) {
                firstColZero=1;
                break;
            }
        }
        for(j=0;j<n;j++){
            if(!matrix[0][j]){
                firstRowZero=1;
                break;
            }
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(i=1;i<m;i++){
            if(!matrix[i][0]) {
                for(j=1;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(j=1;j<n;j++){
            if(!matrix[0][j]){
                for(i=1;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstColZero){
            for(i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
        if(firstRowZero){
            for(j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }

    }
};