ALPHA = 26

def count_bits(x):
    res = 0
    while x:
        res += 1
        x -= x & -x
    return res

class Solution(object):
    def countPalindromicSubsequence(self, s):
        n = len(s)
        dp = [0 for i in xrange(n)]
        
        cur = 0
        for i, c in enumerate(s):
            cur |= 1 << (ord(c) - ord('a'))
            dp[i] = cur
        cur = 0
        dp2 = [0 for i in xrange(ALPHA)]
        for i in xrange(n - 1, -1, -1):
            c = s[i]
            if i - 1 >= 0 and dp[i - 1] & cur:
                dp2[ord(c) - ord('a')] |= dp[i - 1] & cur
            cur |= 1 << (ord(c) - ord('a'))
        res = 0
        for i in xrange(ALPHA):
            res += count_bits(dp2[i])
        return res
