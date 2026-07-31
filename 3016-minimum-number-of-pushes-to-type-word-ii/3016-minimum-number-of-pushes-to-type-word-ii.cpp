class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int i=0,ans=0;
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        for(i=0;i<8;i++){
            ans+=(freq[i])*1;
        }
        for(i=8;i<16;i++){
            ans+=(freq[i])*2;
        }
        for(i=16;i<24;i++){
            ans+=(freq[i])*3;
        }
        for(i=24;i<26;i++){
            ans+=(freq[i])*4;
        }
        return ans;


        
    }
};