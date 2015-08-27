class Solution {
    typedef long long llint;
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        int n = A.size();
        llint ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < A[i]) {
                    cnt++;
                }
            }
            ans += fac(n - i - 1) * cnt;
        }
        return ans + 1;
    }
private:
    llint fac(int x) {
        llint ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= i;
        }
        return ans;
    }
};
