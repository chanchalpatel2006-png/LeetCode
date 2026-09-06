class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n)
            return "";
        vector<int> need(128, 0);
        vector<int> have(128, 0);
        for (char x : t) {
            need[x]++;
        }
        int bestLen = INT_MAX;
        int bestL = 0;
        int l = 0;
        int required = t.size();
        for (int r = 0; r < n; r++) {
            have[s[r]]++;
            if (need[s[r]] > 0 && have[s[r]] <= need[s[r]]) {
                required--;
            }
            while (required == 0) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                have[s[l]]--;

                if (need[s[l]] > 0 && have[s[l]] < need[s[l]])
                    required++;

                l++;
            }
        }

        if (bestLen == INT_MAX)
            return "";

        return s.substr(bestL, bestLen);
    }

}
;