class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n-1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
