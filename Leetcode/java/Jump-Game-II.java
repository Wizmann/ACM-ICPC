public class Solution {
    public int jump(int[] A) {
        int n = A.length;
        if (n <= 1) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int step = 0;
        while (true) {
            int mini = INF;
            int maxi = -INF;
            for (int i = l; i <= r; i++) {
                maxi = Math.max(maxi, i + A[i]);
                mini = Math.min(mini, i + A[i] > 0? 1: 0);
            }
            step += 1;
            if (maxi >= n - 1) {
                break;
            }
            l = mini;
            r = maxi;
        }
        return step;
    }
    final static int INF = 0x3f3f3f3f;
}
