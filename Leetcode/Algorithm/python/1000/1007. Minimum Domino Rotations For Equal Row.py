from collections import Counter

INF = 10 ** 10

class Solution(object):
    def minDominoRotations(self, A, B):
        res = min(self.solve(A, B), self.solve(B, A))
        if res == INF:
            return -1
        return res
        
    def solve(self, A, B):
        c = Counter(A)
        maxf = sorted(c.items(), key=lambda (k, v): v, reverse=True)[0][0]
        cnt = 0
        for i, a in enumerate(A):
            if a == maxf:
                continue
            if B[i] != maxf:
                return INF
            cnt += 1
        return cnt
