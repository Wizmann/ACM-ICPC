from collections import defaultdict

n = int(raw_input())
ns = map(int, raw_input().split())

d = defaultdict(list)

for i, num in enumerate(ns):
    d[num].append(i)

print ' '.join(map(str, sorted(range(1, n + 1), key=lambda x: d[x][1])))


'''
^^^^^TEST^^^^
3
1 1 3 2 3 2 2 3 1
----------
1 3 2
$$$$TEST$$$$


^^^^^TEST^^^^
1
1 1 1
----------
1
$$$$TEST$$$$

^^^^^TEST^^^^
4
2 3 4 3 4 1 3 1 1 4 2 2
----------
3 4 1 2
$$$$TEST$$$$
'''
