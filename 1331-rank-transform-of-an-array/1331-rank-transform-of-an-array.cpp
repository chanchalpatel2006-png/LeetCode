class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        int n=arr.size(),rank=1;
        if(n==0) return arr;
        unordered_map<int,vector<int>> hash;
        for(int i=0;i<n;i++){
            hash[arr[i]].push_back(i);
        }
        for(int i=1;i<n;i++){
            if(copy[i]!=copy[i-1]){
                rank++;
            }
            for(int j:hash[copy[i]])
                arr[j]=rank;
        }
        for(int j:hash[copy[0]])
                arr[j]=1;

        return arr;
    }
};