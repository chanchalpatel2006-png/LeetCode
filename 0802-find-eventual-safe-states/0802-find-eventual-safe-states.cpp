class Solution {
public:
    bool cycleDetected(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&safe){
        vis[node]=1;
        safe[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(cycleDetected(it,graph,vis,safe)){
                    return true;
                }
            }
            else if(!safe[it]) {
                return true;
            }
        }
        safe[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> safe(V,1);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cycleDetected(i,graph,vis,safe);
            }
        }
        vector<int> result;
        for(int i=0;i<V;i++){
            if(safe[i]){
                result.push_back(i);
            }
        }
        return result;

        
    }
};