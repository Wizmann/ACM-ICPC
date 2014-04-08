class Solution {
public:
    int singleNumber(int A[], int n) {
        int cnt[32] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                cnt[j] += (A[i] & (1 << j))? 1 : 0;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int u = cnt[i] % 3 != 0? 1 : 0;
            res |= u << i;
        }
        return res;
    }
};
