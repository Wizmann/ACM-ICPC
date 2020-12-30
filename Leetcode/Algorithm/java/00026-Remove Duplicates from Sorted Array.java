public class Solution {
    public int removeDuplicates(int[] A) {
        int p = 0;
        int q = 1;
        int n = A.length;
        if (n == 0) {
            return 0;
        }
        while (q < n) {
            if (A[p] != A[q]) {
                p++;
                A[p] = A[q];
            }
            q++;
        }
        return p + 1;
    }
}