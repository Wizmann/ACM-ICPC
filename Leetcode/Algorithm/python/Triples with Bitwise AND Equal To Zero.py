from collections import defaultdict

class Solution(object):
    def countTriplets(self, A):
        d = defaultdict(int)
        n = len(A)
        for i in xrange(n):
            for j in xrange(n):
                d[A[i] & A[j]] += 1
        ans = 0
        for k, v in d.items():
            for y in A:
                if k & y == 0:
                    ans += v
        return ans
                
