INF = 10 ** 10

class Solution(object):
    def minimizeResult(self, expression):
        left, right = expression.split("+")
        res = INF
        exp = ''
        for i in xrange(len(left)):
            for j in xrange(len(right)):
                l1, l2 = left[:i], int(left[i:])
                r1, r2 = right[:j + 1], right[j + 1:]
                
                u = (1 if not l1 else int(l1)) * (1 if not r2 else int(r2)) * (int(l2) + int(r1))
                if u < res:
                    exp = '%s(%s+%s)%s' % (l1, l2, r1, r2)
                    res = u
        return exp
                
