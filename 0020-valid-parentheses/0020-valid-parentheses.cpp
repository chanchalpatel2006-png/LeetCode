char stk[10000];
int top=-1;
void push(char x){
    if (top<10000){
        
    
    top+=1;
    stk[top]=x;
    }
}
char pop(){
    if(top<0){
        return 0;
    }
    top-=1;
    return stk[top+1];
}
char peek(){
    if(top>-1)
    return stk[top];
    return '\0';

}

class Solution {
public:
    bool isValid(string s) {
        top=-1;
        for(int i=0;i<s.length();i++){
            if (s[i]=='['||s[i]=='{'||s[i]=='('){
                push(s[i]);
            }
            else if((s[i]==']' && peek()=='[')||(s[i]=='}' && peek()=='{')||(s[i]==')' && peek()=='(')){
                pop();

            }
            else {
    return false;  // invalid bracket
}
        }
        cout <<top;

        if (top<0){
            return 1;
        }else{
            return 0;
        }
        
    }
};