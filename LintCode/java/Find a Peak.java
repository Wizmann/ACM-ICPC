/* Test case

1) 1     // 0
2) 1 2   // 0 or 1
3) 3 1 2 // 0 or 2
4) 3 4 3 // 1
5) 1 2 1 3 4 5 7 6 // 1 or 7
6) empty array // -1

*/


class Solution {
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    public int findPeak(int[] A) {
        int n = A.length;
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        // assert(n >= 2)
        if (A[0] > A[1]) {
            return 0;
        }
        if (A[n - 1] > A[n - 2]) {
            return n - 1;
        }
        // assert(A[0] < A[1] && A[n - 2] < A[n - 1])
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m] > A[m - 1] && A[m] > A[m + 1]) {
                return m;
            }
            /*
            m - 1 | m | m + 1
              1   | 2 |   3
              3   | 2 |   1
              3   | 1 |   2
              2   | 1 |   3
            */
            if (A[m] < A[m - 1]) {
                // <l, m>
                r = m;
            } else {
                // <m, r>
                l = m;
            }
        }
        // assert(false);
        return -1;
    }
}

