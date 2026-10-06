class Solution(object):
    def combinationSum4(self, nums, target):
        dp = [{0: 1}, {}]
        p = 0
        ans = 0
        while dp[p]:
            q = p ^ 1
            dp[q] = {}
            for (k, v) in dp[p].items():
                if k == target:
                    ans += v
                elif k < target:
                    for num in nums:
                        if k + num <= target:
                            dp[q][k + num] = dp[q].get(k + num, 0) + dp[p][k]
            p = q
        return ans
