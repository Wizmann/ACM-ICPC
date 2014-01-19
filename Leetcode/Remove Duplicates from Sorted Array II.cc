class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int pre = -INF;
        int cnt = 0;
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (pre != A[i]) {
                pre = A[i];
                cnt = 1;
                A[p++] = A[i];
            } else {
                cnt++;
                if (cnt > 2) {
                    continue;
                }
                A[p++] = A[i];
            }
        }
        return p;
    }
    
    static const int INF = 0x3f3f3f3f;
};
