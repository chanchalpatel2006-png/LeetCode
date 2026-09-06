class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                str.push_back(s[i]);
            }
            else if(s[i]>='A' && s[i]<='Z'){
                str.push_back(s[i]-'A'+'a');
            }
            else if(s[i]>='0' && s[i]<='9'){
                str.push_back(s[i]);
            }
        }
        int l=0,r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
        
    }
};