class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[0][j] == target) {
                return true;
            }
        }
        for (i = 0; i < m - 1; i++) {
            if (matrix[i + 1][0] == target)
                return true;
            if (matrix[i + 1][0] > target) {
                for (int j = n - 1; j >= 0; j--) {
                    if (matrix[i][j] == target) {
                        return true;
                    } else if (matrix[i][j] < target) {
                        return false;
                    }
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[m - 1][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};