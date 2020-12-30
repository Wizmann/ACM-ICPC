const int MOD = 1000000000 + 7;

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        int res = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j - 1 > i; j--) {
                auto iter_pair = equal_range(A.begin() + i + 1, A.begin() + j, target - A[i] - A[j]);
                int d = distance(iter_pair.first, iter_pair.second);
                res += d;
                res %= MOD;
            }
        }
        return res % MOD;
    }
};
