class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        stack<char> st;
        st.push(s[0]);
        string ans;
        int i=1;
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