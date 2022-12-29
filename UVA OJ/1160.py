#python3
import sys
sys.setrecursionlimit(123456)


class DisjointSet(object):
    def __init__(self):
        self.father = {}

    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        if fa == fb:
            return False

        self.father[fa] = fb
        return True

    def find_father(self, a):
        if a not in self.father or self.father[a] == a:
            return a

        f = self.find_father(self.father[a])
        self.father[a] = f
        return f

ds = DisjointSet()
cnt = 0
for line in sys.stdin:
    if not line.strip():
        continue
    if line.strip() == '-1':
        print(cnt)
        ds = DisjointSet()
        cnt = 0
        continue
    a, b = map(int, line.split())
    if not ds.make_union(a, b):
        cnt += 1

'''
^^^^^TEST^^^^
1 2
3 4
3 5
3 1
2 3
4 1
2 6
6 5
-1
1 2
3 4
3 5
3 1
2 3
4 1
2 6
6 5
-1
---------
3
3
$$$TEST$$$

^^^^^TEST^^^^
1 2
3 4
-1
---------
0
$$$TEST$$$

^^^^^TEST^^^^
1 2
2 1
-1
---------
1
$$$TEST$$$
'''
