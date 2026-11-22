class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        bool bSeen=false;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                bSeen=true;
            }else if(bSeen){
                return false;
            }
        }
        return true;    
    }
};