class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        stack<char> st;
        string ans;
        int i=0;
        while(i<n){
            if(st.empty()){
                    st.push(s[i]);
                }
            else if(s[i]=='('){
                st.push(s[i]);
                ans.push_back(s[i]);

            }
            else{
                st.pop();
                if(!st.empty()){
                    ans.push_back(s[i]);    
                }
            }
            i++;
        }
        return ans;
        
    }
};