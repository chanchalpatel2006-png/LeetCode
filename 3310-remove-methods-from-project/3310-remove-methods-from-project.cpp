class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n,0);
        vector<bool> sus(n,false);
        for(auto &edge:invocations){
            adj[edge[0]].push_back(edge[1]);
            inDeg[edge[1]]++;
        }
        //bfs
        queue<int> q;
        q.push(k);
        sus[k]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                inDeg[it]--;
                if(!sus[it]){
                    sus[it]=true;
                    q.push(it);
                }
            }
        }
        vector<int> result;
        bool cannotRemove=false;
        for(int i=0;i<n;i++){
  
            if(sus[i] && inDeg[i]>0){
                cannotRemove=true;
                break;
            }
            else if(!sus[i]){
                result.push_back(i);
            }
        }
        if(cannotRemove){
            vector<int> vec(n);
            for(int j=0;j<n;j++){
                vec[j]=j;
            }
            return vec;
        }
        return result;



        
    }
};