# https://leetcode.com/problems/find-all-good-strings/

MOD = (10 ** 9) + 7

def toChar(idx):
    return chr(ord('a') + idx)

class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        self.dp = {}
        a = self.dfs(s2, 0, evil, 0, False)
        
        self.dp = {}
        b = self.dfs(s1, 0, evil, 0, False)
        
        res = a - b + (1 if evil not in s1 else 0)
        return ((res % MOD) + MOD) % MOD
        
    def dfs(self, s, cur, evil, ep, lt):
        if ep == len(evil):
            return 0
        if cur == len(s):
            return 1
        key = (cur, ep, lt)
        if key in self.dp:
            return self.dp[key]
        res = 0
        for i in range(26):
            c = toChar(i)
            sub = evil[:ep] + c
            ep_ = 0
            for i in range(len(sub), 0, -1):
                if sub[-i:] == evil[:i]:
                    ep_ = i
                    break
            if lt == False:
                if c == s[cur]:
                    res += self.dfs(s, cur + 1, evil, ep_, False)
                elif c < s[cur]:
                    res += self.dfs(s, cur + 1, evil, ep_, True)   
            else:
                res += self.dfs(s, cur + 1, evil, ep_, True)
            res %= MOD
        key = (cur, ep, lt)
        self.dp[key] = res
        return res
