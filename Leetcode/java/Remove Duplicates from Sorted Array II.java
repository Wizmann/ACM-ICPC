public class Solution {
    public int removeDuplicates(int[] A) {
        int n = A.length;
        int p = 0, q = 1;
        int cnt = 1;
        if (n == 0) {
            return 0;
        }
        while (q < n) {
            if ((A[p] == A[q] && cnt < 2) || 
                    (A[p] != A[q])) {
                if (A[p] == A[q]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                p++;
                A[p] = A[q];
            }
            q++;
        }
        return p + 1;
    }
}