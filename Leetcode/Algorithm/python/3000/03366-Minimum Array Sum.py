INF = 10 ** 10

class Solution(object):
    def minArraySum(self, nums, kk, op1, op2):
        dp = {}
        n = len(nums)
        dp[(-1, 0, 0)] = 0
        for i in xrange(n):
            cur = nums[i]
            for j in xrange(op1 + 1):
                for k in xrange(op2 + 1):
                    mini = INF
                    mini = min(mini, dp.get((i - 1, j, k), INF) + cur)
                    if j - 1 >= 0:
                        mini = min(mini, dp.get((i - 1, j - 1, k), INF) + (cur + 1) / 2)
                    if cur >= kk:
                        if k - 1 >= 0:
                            mini = min(mini, dp.get((i - 1, j, k - 1), INF) + (cur - kk))
                        if j - 1 >= 0 and k - 1 >= 0:
                            mini = min(mini, dp.get((i - 1, j - 1, k - 1), INF) + (cur - kk + 1) / 2)
                    if (cur + 1) / 2 >= kk and j - 1 >= 0 and k - 1 >= 0:
                        mini = min(mini, dp.get((i - 1, j - 1, k - 1), INF) + (cur + 1) / 2 - kk)
                    dp[(i, j, k)] = mini
                    # print(i, j, k, mini, cur, k)
        mini = INF
        for i in xrange(op1 + 1):
            for j in xrange(op2 + 1):
                mini = min(mini, dp.get((n - 1, i, j), INF))
        return mini
