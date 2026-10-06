from collections import defaultdict

class Solution(object):
    def isReflected(self, points):
        d = defaultdict(list)
        for (x, y) in points:
            d[y].append(x)
            
        pivot = None
        for y in d.keys():
            d[y] = sorted(set(d[y]))
            p, q = 0, len(d[y]) - 1
            while p <= q:
                a, b = d[y][p], d[y][q]
                m = 1.0 * (a + b) / 2
                if pivot == None:
                    pivot = m
                elif pivot != m:
                    return False
                p += 1
                q -= 1
        return True
        
