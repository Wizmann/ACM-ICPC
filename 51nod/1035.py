def loop(x):
    if x == 0:
        return -1
    d = {}
    u = 1
    cnt = 0
    while u:
        u *= 10
        if u in d:
            return cnt - d[u]
        else:
            d[u] = cnt
        u %= x
        cnt += 1
    return -1

maxi = [loop(i) for i in xrange(1024)]
ans = [0 for i in xrange(1024)]
for i in xrange(1, 1024):
    ans[i] = ans[i - 1]
    if maxi[i] > maxi[ans[i - 1]]:
        ans[i] = i
n = int(raw_input())
print ans[n]
