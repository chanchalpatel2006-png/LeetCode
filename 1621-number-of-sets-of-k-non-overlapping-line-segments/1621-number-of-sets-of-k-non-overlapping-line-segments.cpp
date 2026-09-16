class Solution {
public:
    int M=1e9+7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }

        for(int i=1;i<=k;i++){
            vector<long long> prevRowSum(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevRowSum[x]=(prevRowSum[x+1]+dp[i-1][x])%M;
            }
            for(int j=n-1;j>=0;j--){
                int skip=dp[i][j+1];
                int take=prevRowSum[j+1];
                dp[i][j]=(take+skip)%M;
            }

        }
        return dp[k][0];
    }
};