class DisjointSet(object):
    def __init__(self, n):
        self.father = [i for i in xrange(n)]
        self.n = n

    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fb] = fa

    def find_father(self, x):
        if self.father[x] == x:
            return x
        self.father[x] = self.find_father(self.father[x])
        return self.father[x]

n = int(raw_input())

ps = []
for i in xrange(n):
    y, x = map(int, raw_input().split())
    ps.append((y, x))

ds = DisjointSet(n)

for i in xrange(n):
    for j in xrange(i + 1, n):
        y1, x1 = ps[i]
        y2, x2 = ps[j]

        if y1 == y2 or x1 == x2:
            ds.make_union(i, j)

s = set()

for i in xrange(n):
    s.add(ds.find_father(i))

print len(s) - 1
