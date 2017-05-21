(n, k) = map(int, raw_input().split())
mat = [ [0 for i in xrange(n)] for j in xrange(n) ]

cur = 0
while k and cur < n:
    mat[cur][cur] = 1
    k -= 1
    if not k:
        break
    m = n - cur - 1
    for i in xrange(m):
        if k <= 1:
            break
        mat[cur][cur + i + 1] = 1
        mat[cur + i + 1][cur] = 1
        k -= 2
    cur += 1

if k:
    print -1
else:
    for line in mat:
        for num in line:
            print num,
        print ''
