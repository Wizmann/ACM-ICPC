MOD = (10 ** 9) + 7

(n, m) = map(int, raw_input().split())

def mat_mul(mat_a, mat_b):
    res = [
        [0 for j in xrange(n)] 
        for i in xrange(n)
    ]
    
    for i in xrange(n):
        for j in xrange(n):
            for k in xrange(n):
                res[i][j] += mat_a[i][k] * mat_b[k][j]
                res[i][j] %= MOD
    return res

mat = [
    map(int, raw_input().split())
    for i in xrange(n)
]

ans = [
    [1 if i == j else 0 for j in xrange(n)]
    for i in xrange(n)
]

while m:
    if m & 1:
        ans = mat_mul(ans, mat)
    mat = mat_mul(mat, mat)
    m >>= 1

for line in ans:
    print ' '.join(map(str, line))
