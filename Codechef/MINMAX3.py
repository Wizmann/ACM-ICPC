(n, k) = map(int, raw_input().split())
ns = map(int, raw_input().split())
ms = []

for i in xrange(1, n):
    a, b = ns[i - 1], ns[i]
    ms.append(a + b)

ms.sort()
#print ms

print sum(ms[:k - 1]) + ns[0] + ns[-1], sum(ms[-k + 1:]) + ns[0] + ns[-1]
