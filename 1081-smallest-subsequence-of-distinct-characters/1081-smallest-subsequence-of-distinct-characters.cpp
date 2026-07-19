class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string result(1,s[0]);
        vector<int> lastIdx(26, -1);
        vector<bool> taken(26, false);
        taken[s[0] - 'a'] = true;
        for(int i=0;i<n;i++){
            lastIdx[s[i] - 'a'] = i;
        }
        for (int i = 1; i < n; i++) {
            if (!taken[s[i]-'a']) {
                while ((!result.empty()) && (result.back() > s[i])) {
                    if (lastIdx[result.back()-'a'] > i) {
                        taken[result.back()-'a'] = false;
                        result.pop_back();
                    }else{
                        break;
                    }
                }
                result+=s[i];
                taken[s[i]-'a']=true;
            }
        }
        return result;
    }
};