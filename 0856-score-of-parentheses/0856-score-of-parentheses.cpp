class Solution {
public:
    int solve(int i, int j, const vector<int>& count) {
        if (i+1==j){
            return 1;
        }
        int A = 0;
        int k=i;
        while (k <= j) {
            if (count[i] == count[k] + 1) {
                if(i+1==k){
                    A++;
                }else{
                    A = A + 2*solve(i+1, k-1, count);
                }
                i = k + 1;
                k = i;
            }
            k++;
        }
        return A;
    }
    int scoreOfParentheses(string s) {
        int n = s.size();
        vector<int> count(n);
        int openCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count[i] = ++openCount;
            } else {
                count[i] = --openCount;
            }
        }
        int ans = 0;
        int i = 0, j = 1;
        while (j < n) {
            if (count[i] == count[j] + 1) {
                if(i+1==j){
                    ans++;
                }else{
                    ans = ans + 2*solve(i+1, j-1, count);
                }
                i = j + 1;
                j = i;
            }
            j++;
        }
        return ans;
    }
};