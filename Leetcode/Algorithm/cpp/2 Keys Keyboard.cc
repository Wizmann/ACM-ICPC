class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                res += i;
                n /= i;
            }
        }
        res += n > 1? n: 0;
        return res;
    }
};
