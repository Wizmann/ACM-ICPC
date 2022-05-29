(n, m) = map(int, raw_input().split())

maze = [raw_input() for i in xrange(n)]

ps = []
for i in xrange(n):
    for j in xrange(m):
        if maze[i][j] == 'o':
            ps.append((i, j))

assert len(ps) == 2

y1, x1 = ps[0]
y2, x2 = ps[1]

print abs(y1 - y2) + abs(x1 - x2)

'''

^^^^^TEST^^^
2 3
--o
o--
--------
3
$$$TEST$$$$ 


^^^^^TEST^^^
5 4
-o--
----
----
----
-o--
--------
4
$$$TEST$$$$ 

'''

