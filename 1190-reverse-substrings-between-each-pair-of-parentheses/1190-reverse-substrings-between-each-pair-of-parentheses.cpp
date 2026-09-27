class Solution {
public:
    pair<string,int> reverseString(string s,int i){
        string ans;
        int n=s.size();
        stack<string> st;
        while(i<n){
            if(s[i]=='('){
                auto[r,j]=reverseString(s,i+1);
                reverse(r.begin(),r.end());
                st.push(r);
                i=j;
            }
            else if(s[i]==')'){
                i++;
                break;
            }
            else{
                st.push(string(1,s[i]));
                i++;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return {ans,i};
    }
    string reverseParentheses(string s) {
        int n=s.size();
        string ans;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                auto[r,j]=reverseString(s,i+1);
                ans+=r;
                i=j;
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};