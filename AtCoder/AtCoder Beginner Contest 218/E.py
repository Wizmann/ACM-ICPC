class DisjointSet(object):
    def __init__(self):
        self.father = {}

    def find_father(self, x):
        if x not in self.father:
            self.father[x] = x
            return x

        if self.father[x] == x:
            return x

        f = x
        while self.father[f] != f:
            f = self.father[f]
        self.father[x] = f
        return f

    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fb] = fa

    def same_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb


tot = 0
n, m = map(int, raw_input().split())
edges = []
for i in xrange(m):
    (a, b, c) = map(int, raw_input().split())
    edges.append((c, a, b))
edges.sort()

e = 0
ds = DisjointSet()
for (c, a, b) in edges:
    if ds.same_union(a, b):
        if c > 0:
            tot += c
        continue
    ds.make_union(a, b)
    e += 1
print tot

'''
^^^TEST^^^
4 5
1 2 1
1 3 1
1 4 1
3 2 2
4 2 2
-------
4
$$$TEST$$$

^^^TEST^^^
3 3
1 2 1
2 3 0
3 1 -1
---------
1
$$$TEST$$$

^^^TEST^^^
2 3
1 2 -1
1 2 2
1 1 3
-------
5
$$$TEST$$$
'''
