class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        long long ans=0;
        int l=0,r=0;
        if(s[0]==' '){
            while(l<n && s[l]==' '){
                l++;
            }
        }
        if(s[l]=='-'){
            sign=-1;
            l++;
        }
        else if(s[l]=='+'){
            l++;
        }
        if(s[l]>='0' && s[l]<='9'){
            r=l;
            while(r<n && s[r]>='0' && s[r]<='9'){
                ans=ans*10+(s[r]-'0');
                if(sign==1 and ans>INT_MAX){
                    return INT_MAX;
                }
                else if(sign==-1 and ans>INT_MAX){
                    return INT_MIN;
                }
                r++;
            }
        }
        return ans*sign;
    }
};