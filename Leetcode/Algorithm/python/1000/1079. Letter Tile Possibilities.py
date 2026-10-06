from collections import Counter

def factorial(n):
    return reduce(lambda x, y: x * y, range(1, n + 1), 1)


class Solution(object):
    def numTilePossibilities(self, tiles):
        n = len(tiles)
        s = set()
        res = 0
        for i in xrange(1 << n):
            l = []
            for j in xrange(n):
                if i & (1 << j):
                    l.append(tiles[j])
            key = ''.join(sorted(l))
            if not key:
                continue
            if key in s:
                continue
            s.add(key)
            
            tot = factorial(len(l))
            c = Counter(l)
            
            for key, value in c.items():
                tot /= factorial(value)
            res += tot
        return res
