class Solution {
public:
    int findGCD(vector<int>& nums) {
        int Max=*max_element(begin(nums),end(nums));
        int Min=*min_element(begin(nums),end(nums));
        return gcd(Max,Min);
    }
};