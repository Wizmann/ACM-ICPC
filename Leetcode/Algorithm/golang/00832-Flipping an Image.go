func flipAndInvertImage(A [][]int) [][]int {
    n := len(A);
    for i := 0; i < n; i++ {
        m := len(A[i]);
        for j := 0; j < m; j++ {
            A[i][j] ^= 1;
        }
        l := 0
        r := m - 1
        for l <= r {
            A[i][l], A[i][r] = A[i][r], A[i][l];
            l++;
            r--;
        }
    }
    return A;
}
