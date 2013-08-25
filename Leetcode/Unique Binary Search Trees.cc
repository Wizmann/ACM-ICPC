class Solution {
public:
    int numTrees(int n) {
        long long x = 1;
        for (int i = 0; i < n; i++) {
            x *= (2 * n - i);
        }
        for (int i = 0; i < n; i++) {
            x /= (i + 1);
        }
        x /= (n + 1);
        return x;
    }
};
