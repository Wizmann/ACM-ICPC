class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int r = 0, next_r = 0;
        for (int i = 0; i < n; i++) {
            if (i <= r) {
                next_r = max(next_r, i + A[i]);
            } else {
                step++;
                if (next_r > r) {
                    r = next_r;
                    i--;
                } else {
                    step = -1;
                    break;
                }
            }
        }
        return step;
    }
};
