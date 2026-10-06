from collections import defaultdict

def word_to_int(word):
    res = 0
    for c in word:
        c = ord(c) - ord('a')
        res += 1 << c
    return res

class DisjointSet(object):
    def __init__(self, n):
        self.father = range(n)
        self.size = [1 for i in xrange(n)]

    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        if fa == fb:
            return
        if self.size[fa] < self.size[fb]:
            fa, fb = fb, fa
        self.father[fb] = fa
        self.size[fa] += self.size[fb]

    def find_father(self, x):
        if self.father[x] == x:
            return x
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f

    def get_size(self, x):
        f = self.find_father(x)
        return self.size[f]

class Solution(object):
    def groupStrings(self, words):
        n = len(words)
        words = map(word_to_int, words)

        ds = DisjointSet(n)
        d = defaultdict(list)

        for i, word in enumerate(words):
            d[word].append(i)

        wild = defaultdict(list)
        for key, _ in d.items():
            for i in xrange(26):
                if key & (1 << i):
                    nxt = key ^ (1 << i)
                    wild[nxt].append(key)

        for key, values in wild.items():
            m = len(values)
            for i in xrange(1, m):
                a = d[values[0]][0]
                b = d[values[i]][0]
                ds.make_union(a, b)

        for key, indexes in d.items():
            index = indexes[0]
            value = key
            for i in xrange(26):
                nxt = value ^ (1 << i)
                if d[nxt]:
                    ds.make_union(index, d[nxt][0])
            m = len(indexes)
            for i in xrange(1, m):
                ds.make_union(indexes[0], indexes[i])
                        
        d2 = defaultdict(int)
        for i in xrange(n):
            # print i, ds.find_father(i), ds.get_size(i)
            d2[ds.find_father(i)] = ds.get_size(i)
        return [len(d2), max(d2.values())]

'''
^^^^TEST^^^
["a","b","ab","cde"]
-------
[2, 3]
$$$TEST$$$

^^^^TEST^^^^
["a","ab","abc"]
------
[1, 3]
$$$TEST$$$
'''

