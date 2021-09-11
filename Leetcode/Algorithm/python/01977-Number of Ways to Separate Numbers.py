from collections import defaultdict

MOD = 10 ** 9 + 7

class Solution(object):
    def numberOfCombinations(self, num):
        num = map(int, num)
        n = len(num)
        
        dp = [ [0 for i in xrange(n)] for j in xrange(n) ]
        lcs = [ [0 for i in xrange(n)] for j in xrange(n) ]
        if not num[0]:
            return 0

        for i in xrange(n):
            dp[0][i] = 1

        for i in xrange(n - 1, -1, -1):
            for j in xrange(n - 1, i, -1):
                if num[i] == num[j]:
                    lcs[i][j] = (lcs[i + 1][j + 1] if i + 1 < n and j + 1 < n else 0) + 1

        def mycmp(l, r, length):
            common = lcs[l][r]
            if common >= length:
                return 0
            return 1 if num[l + common] >= num[r + common] else -1
        
        for i in xrange(1, n):
            r = i
            base = 0
            if num[i] == 0:
                continue
                
            for l in xrange(i - 1, -1, -1):
                ll = i - l
                lr = ll
                r = i + lr - 1

                if not dp[l][i - 1]:
                    continue

                # print ll, lr, mycmp(0, 1, 1), lcs[0][1]

                while r < n and (ll > lr or (ll == lr and mycmp(l, i, ll) > 0)):
                    r += 1
                    lr += 1

                # print ll, lr, r

                if r < n:
                    # print num[l: i], num[i: r + 1]
                    dp[i][r] += dp[l][i - 1]

            for j in xrange(i + 1, n):
                dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD

            # print dp

        res = 0
        for i in xrange(n):
            res = (res + dp[i][n - 1]) % MOD
        print res
        return res

