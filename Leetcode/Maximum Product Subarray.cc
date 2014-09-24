class Solution {
public:
    int maxProduct(int A[], int n) {
        int p = 0, q = 0;
        int ans = -INF;
        int pro = 1;
        for (int i = 0; i <= n; i++) {
            if (i != n && A[i] != 0) {
                pro *= A[i];
                ans = max(pro, ans);
                q = i + 1;
            } else {
                if (i < n && A[i] == 0) {
                    ans = max(ans, 0);
                }
                while (p < q) {
                    pro /= A[p];
                    p++;
                    if (p == q) {
                        break;
                    }
                    ans = max(pro, ans);
                }
                p = q = i + 1;
            }
        }
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
