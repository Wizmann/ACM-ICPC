class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int ans = 0;
        ans = max(ans, LICS(A));
        reverse(A.begin(), A.end());
        ans = max(ans, LICS(A));
        return ans;
    }
private:
    int LICS(const vector<int>& A) {
        int res = 0;
        int cnt = 0;
        int cur = INF;
        
        for (auto i: A) {
            if (i <= cur) {
                res = max(res, cnt);
                cur = i;
                cnt = 1;
            } else {
                cur = i;
                cnt++;
            }
        }
        res = max(res, cnt);
        return res;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
