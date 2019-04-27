n = int(raw_input())
ns = map(int, raw_input().split())
l, r = 0, n - 1

res = []
pre = -1
while l <= r:
    if min(ns[l], ns[r]) > pre:
        if ns[l] < ns[r]:
            pre = ns[l]
            res.append('L')
            l += 1
        else:
            pre = ns[r]
            res.append('R')
            r -= 1
    elif ns[l] > pre:
        pre = ns[l]
        res.append('L')
        l += 1
    elif ns[r] > pre:
        pre = ns[r]
        res.append('R')
        r -= 1
    else:
        break

print len(res)
print ''.join(res)
