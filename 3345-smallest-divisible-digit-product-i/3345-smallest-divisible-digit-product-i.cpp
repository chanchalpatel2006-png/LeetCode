class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n; num < n + 10; num++) {
            int x = num;
            int prod = 1;

            while (x > 0) {
                prod *= x % 10;
                x /= 10;
            }

            if (prod % t == 0)
                return num;
        }

        return -1;
    }
};