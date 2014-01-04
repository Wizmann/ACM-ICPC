(n, k) = map(int, raw_input().split())
ll = map(int, raw_input().split())

ans = 0

for i in xrange(k):
    ones = 0
    twos = 0
    for j in xrange(i, n, k):
        if ll[j] == 1:
            ones += 1
        else:
            twos += 1

    ans += min(ones, twos)

print ans

