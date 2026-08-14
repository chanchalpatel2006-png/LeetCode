class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), mx = 0, j = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            while (freq[s[i] - 'a'] > 2) {
                freq[s[j] - 'a']--;
                j++;
            }
            mx=max(i-j+1,mx);
        }
        return mx;
    }
};