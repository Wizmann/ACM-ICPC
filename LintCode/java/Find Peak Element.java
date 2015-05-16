class Solution {
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    public int findPeak(int[] A) {
        int n = A.length;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m - 1] < A[m] && A[m] > A[m + 1]) {
                return m;
            }
            
            if (A[m] < A[m - 1]) {
                r = m;
            } else {
                l = m;
            }
        }
        return -1;
    }
}

