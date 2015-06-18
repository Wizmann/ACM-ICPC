def solve(n, k):
    if n % (k + 1) == 0:
        return 'B'
    else:
        return 'A'

T = int(raw_input())

for i in xrange(T):
    (n, k) = map(int, raw_input().split())
    print solve(n, k)
