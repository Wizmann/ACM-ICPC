class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        return C(min(m - 1, n - 1), m - 1 + n - 1);
    }
private:
    int C(int a, int b) {
        long long res = 1;
        for (int i = 0; i < a; i++) {
            res *= (b - i);
            res /= (i + 1);
        }
        return res;
    }
};

