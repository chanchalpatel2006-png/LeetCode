class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int x:nums2){
            while(!st.empty() && st.top()<x){
                mp[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        for(int x:nums1){
            if(mp.find(x)!=mp.end()){
                ans.push_back(mp[x]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};