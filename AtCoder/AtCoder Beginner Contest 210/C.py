from collections import defaultdict


(n, k) = map(int, raw_input().split())
ns = map(int, raw_input().split())

res = 0
d = defaultdict(int)

for i in xrange(k):
    d[ns[i]] += 1

tot = len(d.keys())
res = tot

for i in xrange(k, n):
    cur = ns[i]
    pre = ns[i - k]
    if d[cur] == 0:
        tot += 1
    d[cur] += 1
    d[pre] -= 1
    if d[pre] == 0:
        tot -= 1
    res = max(res, tot)

print res

'''
^^^^TEST^^^
7 3
1 2 1 2 3 3 1
-------
3
$$$TEST$$$

^^^TEST^^^
5 5
4 4 4 4 4
------
1
$$$TEST$$$

^^^TEST^^^
10 6
304621362 506696497 304621362 506696497 834022578 304621362 414720753 304621362 304621362 414720753
------
4
$$$TEST$$$

'''
