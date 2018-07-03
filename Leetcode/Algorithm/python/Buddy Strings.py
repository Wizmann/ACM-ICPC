class Solution(object):
    def buddyStrings(self, A, B):
        if len(A) != len(B):
            return False
        n = len(A)
        ps = []
        for i in xrange(n):
            if A[i] != B[i]:
                ps.append((A[i], B[i]))
        if not ps and len(set(A)) < len(A):
            return True
        if len(ps) != 2:
            return False
        if ps[0] != ps[1][::-1]:
            return False
        return True
