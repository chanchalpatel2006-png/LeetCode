class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char> st;
        for (char x:s){
            if(x=='('){
                st.push(x);
                
            }
            else{
                if(st.empty()){
                    count++;
                }
                else{
                    st.pop();
                }    
            }
        }
        return count+st.size();
        
    }
};