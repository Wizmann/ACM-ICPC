class Solution(object):
    def numsSameConsecDiff(self, N, K):
        self.res = set()
        self.dfs(N, K, [])
        return list(self.res)
    
    def dfs(self, N, K, cur):
        if not cur:
            for i in xrange(10):
                self.dfs(N, K, [i])
            return
        else:
            n = len(cur)
            if n == N:
                if len(cur) > 1 and cur[0] == 0:
                    return
                self.res.add(int(''.join(map(str, cur))))
                return
            pre = cur[-1]
            if pre + K < 10:
                self.dfs(N, K, cur + [pre + K])
            if pre - K >= 0:
                self.dfs(N, K, cur + [pre - K])
