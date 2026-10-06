INF = 10 ** 10

class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        ans = 0
        ans_path = []
        n = len(nums)
        for i in xrange(1, n):
            nums[i] += nums[i - 1]
            
        dp = [[-INF for i in xrange(n)] for j in xrange(3)]
        path = [ [ [] for i in xrange(n) ] for j in xrange(3)]
        
        dp[0][k - 1] = nums[k - 1]
        path[0][k - 1] = [0]
        for i in xrange(k, n):
            for j in xrange(3):
                pre = 0 if j == 0 else dp[j - 1][i - k]
                pre_path = [] if j == 0 else path[j - 1][i - k]
                if nums[i] - nums[i - k] + pre > dp[j][i - 1]:
                    dp[j][i] = pre + nums[i] - nums[i - k]
                    path[j][i] = pre_path + [i - k + 1]
                elif nums[i] - nums[i - k] + pre == dp[j][i - 1]:
                    dp[j][i] = pre + nums[i] - nums[i - k]
                    path[j][i] = min(pre_path + [i - k + 1], path[j][i - 1])
                else:
                    dp[j][i] = dp[j][i - 1]
                    path[j][i] = path[j][i - 1]
        
        for i in xrange(n):
            if dp[2][i] > ans:
                ans = dp[2][i]
                ans_path = path[2][i]
        return ans_path
