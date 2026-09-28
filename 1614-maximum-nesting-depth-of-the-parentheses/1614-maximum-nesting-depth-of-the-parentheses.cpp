class Solution {
public:
    int maxDepth(string s) {
        int n=s.size(),m=0;
        int c=0;
        for(char ch:s){
            if(ch=='('){
                c++;
                m=max(m,c);
            }else if(ch==')'){
                c--;
            }
        }
        return m;
        
    }
};