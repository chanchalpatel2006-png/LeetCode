class Solution {
public:
    string binarySearch(vector<vector<string>>&knowledge,string key){
        int l=0,r=knowledge.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(knowledge[mid][0]==key){
                return knowledge[mid][1];
            }
            else if(knowledge[mid][0]>key){
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return "?";
    }

    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        int n=s.size();
        sort(knowledge.begin(),knowledge.end());
        string ans;
        while(i<n){
            if(s[i]=='('){
                i++;
                string k="";
                while(s[i]!=')'){
                    k.push_back(s[i]);
                    i++;
                }
                ans+=binarySearch(knowledge,k);
                i++;
                
            }
            else{
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};