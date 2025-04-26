class Solution(object):
    def numSpecialEquivGroups(self, A):
        for i in xrange(len(A)):
            A[i] = ''.join(sorted(A[i][::2]) + sorted(A[i][1::2]))
        return len(set(A))
