class Solution(object):
    def advantageCount(self, A, B):
        n = len(B)
        res = [0 for i in xrange(n)]
        sa, sb = sorted(A), sorted(range(n), key=lambda i: B[i])
        while sa and sb:
            if sa[-1] > B[sb[-1]]:
                res[sb[-1]] = sa[-1]
                sa.pop()
            else:
                res[sb[-1]] = sa[0]
                sa.pop(0)
            sb.pop()
        return res
