class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        long long l = 0;
        long long r = x;
        
        while (l <= r) {
            long long m = (l + r) / 2;
            if (m * m > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
