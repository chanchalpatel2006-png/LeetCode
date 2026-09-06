#include <bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int l=INT_MAX;
        
        string ans="";
        for(auto s:strs){
            l=min(l,(int)s.size());
        }
        int i=0;
        while(i<l){
            bool flag=false;
            for(int j=1;j<n;j++){

                if(strs[j][i]!=strs[0][i]){
                    flag=true;
                    break;
                }
                
            }
            if(flag) break;
            ans.push_back(strs[0][i]);
            i++;
        }
        return ans;
        
    }
};