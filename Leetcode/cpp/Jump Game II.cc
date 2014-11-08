class Solution {
public:
    int jump(int A[], int n) {
        int s = -1;
        int r = -1, next_r = 0;
        
        for (int i = 0; i < n; i++) {
            if (i > r) {
                s += 1;
                r = next_r;
                if (r >= n - 1) {
                    break;
                }
            }
            next_r = max(next_r, i + A[i]);
        }
        return s;
    }
};
