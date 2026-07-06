class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int i=1;
        while(i<n){
            if(intervals[i][0]>=intervals[i-1][0] && intervals[i][1]<=intervals[i-1][1]){
                intervals.erase(intervals.begin()+i);
                n--;
            }
            else{
                i++;
            }
        }
        return intervals.size();
        
    }
};