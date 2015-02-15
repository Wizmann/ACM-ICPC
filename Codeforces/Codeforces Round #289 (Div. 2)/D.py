(n, m) = map(int, raw_input().split())

mat = [map(int, raw_input().split()) for i in xrange(n)]

mod = -1
diffs = [0 for i in xrange(m)]

for i in xrange(1, m):
    diff = set([
        mat[j][i] - mat[j][0] for j in xrange(n)
    ])

    if len(diff) == 1:
        diffs[i] = list(diff)[0]
        continue

    if len(diff) != 2:
        print 'NO'
        exit(0)

    a, b = diff

    if mod == -1:
        mod = abs(a - b)
    elif mod != abs(a -b):
        print 'NO'
        exit(0)

    diffs[i] = max(a, b)

As = [0 for i in xrange(n)]
Bs = [0] + diffs[1:]

Bs = map(lambda x: x - min(Bs), Bs)


for i in xrange(n):
    As[i] = mat[i][0] - Bs[0]

if mod == -1:
    mod = (10 ** 18) - 1

for i in xrange(n):
    for j in xrange(m):
        if mat[i][j] != (As[i] + Bs[j]) % mod:
            print 'NO'
            exit(0)

print 'YES'
print mod
print ' '.join(map(str, As))
print ' '.join(map(str, Bs))

