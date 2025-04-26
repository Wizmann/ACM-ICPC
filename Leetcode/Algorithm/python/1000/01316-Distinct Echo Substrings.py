MOD = 0xdeadbeef

class Solution(object):
    def distinctEchoSubstrings(self, text):
        n = len(text)
        dp = [ [0 for i in xrange(n)] for j in xrange(n) ]
        
        for i in xrange(n):
            for j in xrange(n):
                if i + j >= n:
                    break
                c = ord(text[i + j]) - ord('a') + 1
                if i == 0:
                    dp[j][i + j] = c % MOD
                else:
                    dp[j][i + j] = (dp[j][i + j - 1] * 29 + c) % MOD
                    
        res = set()
        for i in xrange(n):
            for j in xrange(i, n):
                h1 = dp[i][j]
                if h1 in res:
                    continue
                l = j + 1
                r = j + 1 + (j - i)
                if r < n:
                    h2 = dp[l][r]
                    if h1 == h2:
                        # print i, j, j + 1, j + 1 + l - 1
                        res.add(h1)
                else:
                    break
        return len(res)
