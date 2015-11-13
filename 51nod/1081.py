n = int(raw_input())
ns = [0] + [int(raw_input()) for i in xrange(n)]

for i in xrange(1, n + 1):
    ns[i] += ns[i - 1]

q = int(raw_input())
for i in xrange(q):
    (a, b) = map(int, raw_input().split())
    print ns[a + b - 1] - ns[a - 1]
