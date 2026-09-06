class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>freq(128,0);
        int l=0,r=0;
        int best=0;
        while(l<=r && r<n){
            freq[s[r]]++;
            while(freq[s[r]]!=1){
                freq[s[l]]--;
                l++;
            }
            best=max(best,r-l+1);
            r++;
        }

        return best;
        
    }
};