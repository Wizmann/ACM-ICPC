from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def subarraysWithKDistinct(self, A, K):
        n = len(A)
        d = defaultdict(int)
        p1, p2 = 0, 0
        res = 0
        for i in xrange(n):
            d[A[i]] += 1
            
            if len(d) > K:
                del d[A[p2]]
                p2 += 1
                p1 = p2
            if len(d) == K:
                while d[A[p2]] > 1:
                    d[A[p2]] -= 1
                    p2 += 1
                res += p2 - p1 + 1
        return res
                
            
