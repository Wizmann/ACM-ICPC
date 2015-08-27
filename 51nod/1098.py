import sys
sys.stdin = open('input.txt')

(n, m) = map(int, raw_input().split())
ns = map(int, [raw_input() for i in xrange(n)])

ns.sort()
ns.append(-1)

a, b = 0.0, 0.0
for i in xrange(m):
    a += ns[i] * ns[i]
    b += ns[i]
    
ans = 1.0 * 0xdeadbeef
for i in xrange(m, n + 1):
    ave = 1.0 * b / m
    u = a - 2 * ave * b + m * ave * ave

    ans = min(ans, u)
    a -= ns[i - m] * ns[i - m]
    a += ns[i] * ns[i]
    b -= ns[i - m]
    b += ns[i]

print int(ans)
