import sys

N = 20

matrix = [
    map(int, line.split()) for line in sys.stdin
]

ans = 0
for i in xrange(N):
    for j in xrange(N):
        if i + 3 < N:
            ans = max(ans, matrix[i][j] * matrix[i + 1][j] * matrix[i + 2][j] * matrix[i + 3][j])
        if j + 3 < N:
            ans = max(ans, matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3])
        if i + 3 < N and j + 3 < N:
            ans = max(ans, matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3])
        if i + 3 < N and j - 3 >= 0:
            ans = max(ans, matrix[i][j] * matrix[i + 1][j - 1] * matrix[i + 2][j - 2] * matrix[i + 3][j - 3])
print ans

