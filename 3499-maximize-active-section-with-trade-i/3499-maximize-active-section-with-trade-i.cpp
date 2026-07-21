class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size(),active=0,zero=0;
        vector<int> Z;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                active++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }
            else if(s[i]='1' && zero>0){
                Z.push_back(zero);
                zero=0;
            }
        }
        if(s[n-1]=='0')  Z.push_back(zero);
        int mx=0;
        if(Z.size()<2) return active;
        for(int i=0;i<Z.size()-1;i++){
            mx=max(mx,Z[i]+Z[i+1]);
        }
        return active+mx;

        
    }
};