class Solution(object):
    def findLatestStep(self, arr, k):
        n = len(arr)
        if n == k:
            return n
        dp = [0 for i in xrange(n)]
        res = -1
        for i, num in enumerate(arr):
            num -= 1
            l, r = num, num
            if num - 1 >= 0:
                l = num - dp[num - 1]
            if num + 1 < n:
                r = num + dp[num + 1]
            length = r - l + 1
            if k in [dp[l], dp[r]]:
                res = i
            dp[l] = length
            dp[r] = length
        return res
