class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size(),j,i;
        sort(s.begin(),s.begin()+n/2);
        i=(n&1)?n/2+1:n/2;
        
        for(j=n/2-1;j>=0;j--){
            s[i]=s[j];
            i++;
        }
        return s;
    }
};