from collections import defaultdict

class Solution(object):
    def longestSubsequence(self, arr, diff):
        n = len(arr)
        dp = {}
        for i in xrange(n - 1, -1, -1):
            cur = arr[i]
            nxt = cur + diff
            dp[cur] = dp.get(nxt, 0) + 1
        return max(dp.values())
