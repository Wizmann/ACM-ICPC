MOD = (10 ** 9) + 7

class Solution(object):
    def numMusicPlaylists(self, N, L, K):
        c = 1
        res = self.solve(N, L, K)
        for i in xrange(1, N):
            c *= N - i + 1
            c /= i
            
            res += ((-1) ** i) * self.solve(N - i, L, K) * c
            res %= MOD
        return res
            
    def solve(self, N, L, K):
        pre = 1
        for i in xrange(L):
            u = max(N - i, N - K, 0)
            pre = pre * u % MOD
        return pre
