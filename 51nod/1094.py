(n, k) = map(int, raw_input().split())
ns = [int(raw_input()) for i in xrange(n)]

pre_sum = {0: -1}
s = 0
res = []

for i, num in enumerate(ns):
    s += num
    if s not in pre_sum:
        pre_sum[s] = i
    # print s - k, pre_sum
    if s - k in pre_sum:
        l = pre_sum[s - k] + 1
        r = i + 1
        res.append((l + 1, r))
if not res:
    print 'No Solution'
else:
    print ' '.join(map(str, sorted(res)[0]))
