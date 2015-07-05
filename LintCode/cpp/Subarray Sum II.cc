class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        int a = solve(A, [start](int x) {
            return x >= start;
        });
        int b = solve(A, [end](int x) {
            return x > end;
        });
        return a - b;
    }
private:
    int solve(const vector<int>& A, function<int(int)> fun) {
        int n = A.size();
        int sum = A[0];
        int p = -1;
        int q = 0;
        int ans = 0;
        
        while (p < n && q < n) {
            sum -= p >= 0? A[p]: 0;
            while (q < n && !fun(sum)) {
                q++;
                sum += A[q];
            }
            ans += n - q;
            p++;
        }
        return ans;
    }
};
