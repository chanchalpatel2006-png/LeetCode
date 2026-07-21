class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), active = 0, zero = 0;
        int mx = 0;
        int prev = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                active++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zero++;
            } else if (s[i] == '1' && zero > 0 ) {
                curr = zero;
                if(prev>0) mx = max(mx, prev + curr);
                prev = curr;
                zero = 0;
            }
        }
        if (zero > 0) {
            curr = zero;
            if(prev>0) mx = max(mx, prev + curr);
            prev = curr;
            zero = 0;
        }
        return active + mx;
    }
};