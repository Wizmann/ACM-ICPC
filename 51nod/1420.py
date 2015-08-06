n = int(raw_input())
ns = sorted([int(raw_input()) for i in xrange(n)])

p = n / 2 - 1
q = n - 1
ans = 0
while p >= 0 and q >= 0:
    if ns[p] * 2 <= ns[q]:
        ans += 1
        p -= 1
        q -= 1
    else:
        p -= 1
print n - ans
