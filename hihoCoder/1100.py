INF = 0x3f3f3f3f

(n, m, h, r) = map(int, raw_input().split())
ns = sorted(map(int, raw_input().split()))

sections = []

for i, item in enumerate(ns):
    if not sections or item - ns[sections[-1]['last']] > m:
        sections.append({'begin': i, 'last': i})
    else:
        sections[-1]['last'] = i

cur = 0

for item in sections[::-1]:
    for i in xrange(item['begin'], item['last'] + 1):
        limit = r + cur
        u = ns[i]
        if u <= limit:
            cur += 1
        else:
            break
print min(h, cur)
