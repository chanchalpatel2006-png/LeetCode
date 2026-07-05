class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i = 0;

       
        int t = 0, b = m - 1;
        while (t <= b) {
            int mid1 = t + (b - t) / 2;
            if (matrix[mid1][0] <= target && matrix[mid1][n - 1] >= target) {
                int l = 0, h = n - 1;
                while (l <= h) {
                    int mid = l + (h - l) / 2;
                    if (matrix[mid1][mid] == target) {
                        return true;
                    } else if (matrix[mid1][mid] > target) {
                        h = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                return false;
            }
            else if(matrix[mid1][0]>target){
                b=mid1-1;
            }
            else{
                t=mid1+1;
            }
        }

        return false;
    }
};