public class Solution {
    public int trap(int[] A) {
        int n = A.length;
        int max_left = 0, max_right = 0;
        int p = 0, q = n - 1;
        int ans = 0;
        while (p < q) {
            if (A[p] < A[q]) {
                max_left = Math.max(max_left, A[p]);
                ans += max_left - A[p];
                p++;
            } else {
                max_right = Math.max(max_right, A[q]);
                ans += max_right - A[q];
                q--;
            }
        }
        return ans;
    }
}