class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size(),mx;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<n){
            vector<int> interval;
            interval.push_back(intervals[i][0]);
            mx=intervals[i][1];
            while(i<n-1 && mx>=intervals[i+1][0]){
                i++;
                mx=max(mx,intervals[i][1]);
            }
            interval.push_back(mx);
            ans.push_back(interval);
            i++;
        }
        return ans;
        
    }
};