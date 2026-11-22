class Solution {
public:
    bool checkString(string s) {
        bool bSeen=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                bSeen=true;
            }else if(bSeen){
                return false;
            }
        }
        return true;    
    }
};