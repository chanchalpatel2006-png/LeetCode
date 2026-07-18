class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int kids=g.size(),cookies=s.size();
        int contentKids=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(j=0;j<cookies;j++){
            if(g[i]<=s[j]){
                contentKids++;
                i++;
            }
            if(contentKids==kids) return contentKids;
        }
        return contentKids;
    }
};