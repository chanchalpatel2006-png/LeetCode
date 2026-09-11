class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> mp(10,0);
        for(int x:digits){
            mp[x]++;
        }
        int c=0;
        for(int i=1;i<=9;i++){
            if(!mp[i]) continue;
            mp[i]--;
            for(int j=0;j<=9;j++){
                if(!mp[j]) continue;
                mp[j]--;
                for(int k=0;k<=8;k=k+2){
                    if(!mp[k]) continue;
                    mp[k]--;
                    c++;
                    mp[k]++;
                    
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return c;
        
    }
};