class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false; 
        vector<int> Freq(26,0);
        for(int i=0;i<s.size();i++){
            Freq[s[i]-'a']++;
            Freq[t[i]-'a']--;
        }
        for(int x:Freq){
            if(x!=0) return false;
        }
        return true;
    }
};