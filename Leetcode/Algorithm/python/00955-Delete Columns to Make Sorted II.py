class Solution(object):
    def minDeletionSize(self, A):
        n = len(A)
        if n == 0:
            return 0
        m = len(A[0])
        
        cnt = 0
        res = ['' for i in xrange(n)]
        for i in xrange(m):
            flag = True
            for j in xrange(n - 1):
                if res[j] + A[j][i] > res[j + 1] + A[j + 1][i]:
                    flag = False
                    break
            if flag:
                for j in xrange(n):
                    res[j] += A[j][i]
                cnt += 1
        return m - cnt
