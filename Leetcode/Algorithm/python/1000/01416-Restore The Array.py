MOD = (10 ** 9) + 7

class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        self.d = {}
        return self.dfs(0, s, k)
        
    def dfs(self, ptr, s, k):
        if ptr in self.d:
            return self.d[ptr]
        if ptr == len(s):
            return 1
        if s[ptr] == '0':
            return 0
        
        qtr = ptr
        cur = 0
        res = 0
        while cur <= k and qtr < len(s):
            cur = cur * 10 + int(s[qtr])
            qtr += 1
            if cur <= k:
                res += self.dfs(qtr, s, k)
                res %= MOD
        self.d[ptr] = res
        return res
