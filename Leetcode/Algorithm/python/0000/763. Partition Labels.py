INF = 10 ** 10

class Solution(object):
    def partitionLabels(self, S):
        maxpos = {}
        
        for i, c in enumerate(S):
            maxpos[c] = max(maxpos.get(c, 0), i)
            
        st, p, q = 0, 0, 0
        n = len(S)
        ans = []
        while p < n:
            q = max(q, maxpos[S[p]])
            if p == q:
                ans.append(p - st + 1)
                st = p + 1
            p += 1
            
        return ans
