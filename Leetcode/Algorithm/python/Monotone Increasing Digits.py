class Solution(object):
    def monotoneIncreasingDigits(self, N):
        n = len(str(N))
        return self.dfs(0, 0, n, N)
    
    def dfs(self, prefix, ptr, len, N):
        if ptr == len:
            return prefix
        
        nn = int(str(N)[:ptr + 1])
        pp = -1 if prefix == 0 else int(str(prefix)[-1])

        for i in xrange(9, pp - 1, -1):
            u = prefix * 10 + i
            if u > nn:
                continue
            res = self.dfs(u, ptr + 1, len, N)
            if res != -1:
                return res
        return -1
        
assert Solution().monotoneIncreasingDigits(1234) == 1234
assert Solution().monotoneIncreasingDigits(10) == 9
assert Solution().monotoneIncreasingDigits(332) == 299
assert Solution().monotoneIncreasingDigits(114191537) == 113999999
