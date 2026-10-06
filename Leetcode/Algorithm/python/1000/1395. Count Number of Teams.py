# https://leetcode.com/problems/count-number-of-teams/

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ps = sorted(enumerate(rating), key=lambda p: p[1])
        dp = [0 for i in range(n)]
        res = 0
        for (i, v) in ps:
            dp[i] = 1
            a, b = sum(dp[:i]), (n - i - 1 - sum(dp[i + 1:]))
            res += a * b
            a, b = i - sum(dp[:i]), sum(dp[i + 1:])
            res += a * b
        return res
