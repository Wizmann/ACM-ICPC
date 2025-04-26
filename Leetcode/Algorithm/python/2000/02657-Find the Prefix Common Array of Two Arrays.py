from collections import defaultdict

class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        da = defaultdict(int)
        db = defaultdict(int)
        n = len(A)
        res = []
        cnt = 0
        for i in xrange(n):
            a, b = A[i], B[i]
            da[a] += 1
            db[b] += 1
            if a == b:
                cnt += 1
            else:
                cnt += 1 if da[a] <= db[a] else 0
                cnt += 1 if da[b] >= db[b] else 0
            res.append(cnt)
            
        return res
