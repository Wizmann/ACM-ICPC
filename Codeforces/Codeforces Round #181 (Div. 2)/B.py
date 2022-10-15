from collections import defaultdict


n, m = map(int, raw_input().split())

g = defaultdict(list)


for i in xrange(m):
    a, b = map(int, raw_input().split())
    g[a].append(b)
    g[b].append(a)

visited = set()
flag = True

def dfs(cur, path):
    if cur in visited:
        return
    path.append(cur)
    visited.add(cur)
    for nxt in g[cur]:
        dfs(nxt, path)

teams = []
rems = []

for i in xrange(1, n + 1):
    if i in visited:
        continue
    team = []
    dfs(i, team)

    if len(team) > 3:
        flag = False
        break
    if len(team) >= 2:
        teams.append(team)
    else:
        rems.append(i)

if flag:
    for team in teams:
        if len(team) == 2 and rems:
            team.append(rems.pop())

    for i in xrange(0, len(rems), 3):
        teams.append(rems[i: i + 3])

    for team in teams:
        if len(team) != 3:
            flag = False
            break

if flag:
    for team in teams:
        print ' '.join(map(str, sorted(team, reverse=True)))
else:
    print -1
        

'''
^^^^TEST^^^
3 0
---------------
3 2 1
$$$$$$$TEST$$$$

^^^^TEST^^^
6 0
---------------
3 2 1
6 5 4
$$$$$$$TEST$$$$


^^^^TEST^^^
4 0
---------------
-1
$$$$$$$TEST$$$$

^^^^^^^^^^^TEST^^^^
6 4
1 2
2 3
3 4
5 6
-------
-1
$$$$TEST$$$

^^^^TEST^^^^
3 3
1 2
2 3
1 3
----------
3 2 1
$$$TEST$$$

'''


