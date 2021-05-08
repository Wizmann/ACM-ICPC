MOD = 200


n = int(raw_input())
ns = map(int, raw_input().split())

n = min(8, n)

d = {}

a, b = -1, -1

for i in xrange(1, 1 << n):
    tot = 0
    for j in xrange(n):
        if i & (1 << j):
            tot += ns[j]
    tot %= MOD
    if tot in d:
        a, b = d[tot], i
        break
    d[tot] = i

if a == -1 and b == -1:
    print "NO"
else:
    print "YES"
    A = []
    for i in xrange(n):
        if a & (1 << i):
            A.append(i + 1)
    print len(A), ' '.join(map(str, A))

    B = []
    for i in xrange(n):
        if b & (1 << i):
            B.append(i + 1)
    print len(B), ' '.join(map(str, B))


