class Solution {
public:
    vector<int> ans;
    void generateNumber(int first_digit,int len,int high){
        if(first_digit+len-1>9){
            first_digit=1;
            len++;
        }
        long long num=first_digit;
        int next_digit=first_digit+1;
        for(int i=0;i<len-1;i++){
            num=num*10+next_digit;
            next_digit++;
        }
        if(num<=high){
            ans.push_back(num);
        }
        else{
            return;
        }
        first_digit++;
        if(num%10==9){
            len++;
            first_digit=1;
        }
        
        generateNumber(first_digit,len,high);

    }
    vector<int> sequentialDigits(int low, int high) {
        int len=0,l=low,first_digit=0;
        while(l>0){
            first_digit=l%10;
            l=l/10;
            len++;
        }
        generateNumber(first_digit,len,high);
        if(!ans.empty() && ans[0]<low){
            ans.erase(ans.begin());
        }
        return ans;    
    }
    
};