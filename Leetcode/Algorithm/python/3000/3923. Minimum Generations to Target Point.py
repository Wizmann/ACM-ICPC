class Solution(object):
    def minGenerations(self, points, target):
        cur = set(map(tuple, points))
        target = tuple(target)
        nxt = set()
        if target in cur:
            return 0
        k = 1
        while len(cur) > 1:
            pre = len(cur)
            nxt = set()
            n = len(cur)
            for p1 in cur:
                for p2 in cur:
                    x1, y1, z1 = p1
                    x2, y2, z2 = p2
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    z3 = (z1 + z2) / 2
                    nxt.add((x3, y3, z3))
            if target in nxt:
                return k
            k += 1
            cur = nxt
            if len(cur) == pre:
                break
        
        return -1
