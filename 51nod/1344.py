n = int(raw_input())
ns = [int(raw_input()) for i in xrange(n)]

res = 1
for num in ns[::-1]:
    if num < 0:
        res += abs(num)
    else:
        res = max(0, res - num)
print res
