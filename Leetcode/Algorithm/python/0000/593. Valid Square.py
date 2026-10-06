class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        ps = [p1, p2, p3, p4]
        n = 4
        s = set()
        for i in xrange(n):
            for j in xrange(n):
                if i == j:
                    continue
                dis = ((ps[i][0] - ps[j][0]) ** 2) + ((ps[i][1] - ps[j][1]) ** 2)
                s.add(dis)
        if len(s) != 2:
            return False
        if min(s) * 2 != max(s):
            return False
        return True
        
