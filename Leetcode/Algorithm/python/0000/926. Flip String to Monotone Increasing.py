INF = 10 ** 10

class Solution(object):
    def minFlipsMonoIncr(self, S):
        S = map(int, S)
        tot = sum(S)
        n = len(S)
        
        ans = n - tot
        pre = 0
        
        for i in xrange(n):
            pre += S[i]
            ans = min(ans, pre + (n - i - 1 - tot + pre))
        return ans
