class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int component=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                component++;

                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j] && !vis[j]){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return component;
    }
};