(n, d) = map(int, raw_input().split())

ps = []
for i in xrange(n):
    (x, y) = map(int, raw_input().split())
    ps.append((x, y))

def pdis(a, b):
    xa, ya = ps[a]
    xb, yb = ps[b]
    return (xa - xb) ** 2 + (ya - yb) ** 2

affected = set([0])

q = [0]

while q:
    cur = q.pop(0)
    for i in xrange(n):
        if i in affected or i == cur:
            continue

        if pdis(cur, i) <= d * d:
            q.append(i)
            affected.add(i)

for i in xrange(n):
    if i in affected:
        print 'Yes'
    else:
        print 'No'

'''
^^^^TEST^^^^
4 5
2 -1
3 1
8 8
0 5
---------------
Yes
Yes
No
Yes
$$$$TEST$$$$


^^^^TEST^^^^
3 1
0 0
-1000 -1000
1000 1000
---------------
Yes
No
No
$$$$TEST$$$$

^^^^TEST^^^^
9 4
3 2
6 -1
1 6
6 5
-2 -3
5 3
2 -3
2 1
2 6
---------------
Yes
No
No
Yes
Yes
Yes
Yes
Yes
No
$$$$TEST$$$$
'''
