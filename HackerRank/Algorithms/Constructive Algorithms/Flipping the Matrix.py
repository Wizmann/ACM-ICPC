def solve(n, mat):
    ans = 0
    for i in xrange(n):
        for j in xrange(n):
            ans += max(
                mat[i][j],
                mat[2 * n - i - 1][j],
                mat[i][2 * n - j - 1],
                mat[2 * n - i - 1][2 * n - j - 1]
            )
    return ans

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    mat = []
    for i in xrange(2 * n):
        line = map(int, raw_input().split())
        mat.append(line)

    ans = solve(n, mat)
    print ans
