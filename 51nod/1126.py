def matrix_mul(a, b):
    c = [
        [0, 0],
        [0, 0]
    ]
    for i in xrange(2):
        for j in xrange(2):
            for k in xrange(2):
                c[i][j] += (a[i][k] * b[k][j]) % 7
    return c

def matrix_pow(mat, n):
    res = [
        [1, 0],
        [0, 1]
    ]
    while n:
        if n & 1:
            res = matrix_mul(res, mat)
        mat = matrix_mul(mat, mat)
        n >>= 1
    return res

(A, B, N) = map(int, raw_input().split())

matrix = [
    [0, B],
    [1, A]
]

matrix = matrix_pow(matrix, N - 1)

print matrix

if N <= 2:
    print 1
else:
    print (matrix[0][0] + matrix[1][0]) % 7
