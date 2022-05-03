class Solution(object):
    def maxValueOfCoins(self, piles, k):
        dp = [ [-1 for j in xrange(k + 1)] for i in xrange(2) ]

        p = 0
        dp[0][0] = 0
        for pile in piles:
            cnt = 0
            tot = 0
            q = p ^ 1
            dp[q] = dp[p][:]
            for num in pile:
                cnt += 1
                tot += num

                for i in xrange(k + 1):
                    if dp[p][i] >= 0 and i + cnt <= k:
                        dp[q][i + cnt] = max(dp[q][i + cnt], dp[p][i] + tot)
            p = q
        return max(dp[p])


'''
^^^^^TEST^^^^
[[1,100,3],[7,8,9]]
2
-------
101
$$$TEST$$$$

^^^^^TEST^^^^
[[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]]
7
-------
706
$$$TEST$$$$

'''

        
