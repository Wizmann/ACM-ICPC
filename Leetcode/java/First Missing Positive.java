public class Solution {
    public int firstMissingPositive(int[] A) {
        int n = A.length;
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (A[i] > n || A[i] <= 0) {
                continue;
            }
            while (A[i] != i + 1) {
                if (A[i] > n || A[i] <= 0 || A[i] == A[A[i] - 1]) {
                    break;
                }
                int tmp = A[i];
                A[i] = A[tmp - 1];
                A[tmp - 1] = tmp;
            }
        }
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
}
