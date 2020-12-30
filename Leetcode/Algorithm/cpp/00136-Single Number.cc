class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= A[i];
        }
        return res;
    }
};
