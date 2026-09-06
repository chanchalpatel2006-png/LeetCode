class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0],r=intervals[0][1];
        for(auto interval:intervals){
            if(interval[0]>r){
                result.push_back({l,r});
                l=interval[0];
            }
            r=max(r,interval[1]);
        }
        result.push_back({l,r});
        return result;
        
    }
};