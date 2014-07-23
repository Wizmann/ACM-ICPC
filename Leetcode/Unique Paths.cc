class Solution {
public:
    int uniquePaths(int m, int n) {
        int v = m + n - 2;
        long long res = 1;
        int u = min(m - 1, n - 1);
        for (int i = 0; i < u; i++) {
            res *= v - i;
            res /= (i + 1);
        }
        return res;
    }
};
