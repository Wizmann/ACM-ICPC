typedef long long llint;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int n = A.size();
        if (n < 3) {
            return 0;
        }

        llint diff = A[0] - A[1];
        int p = 0;
        int q = 1;
        
        int ans = 0;
        while (q + 1 < n) {
            if (1LL * A[q] - A[q + 1] != diff) {
                ans += calc(q - p + 1);
                p = q;
                diff = A[q] - A[q + 1];
            } else {
                q++;
            }
        }
        return ans + calc(q - p + 1);
    }
private:
    int calc(int n) {
        if (n <= 2) {
            return 0;
        }
        return 1LL * n * (n - 1) / 2 - n + 1;
    }
};
