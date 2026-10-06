MOD = (10 ** 9) + 7
from collections import defaultdict

class Solution(object):
    def maxSum(self, nums1, nums2):
        self.nums = [nums1, nums2]
        self.d = defaultdict(int)
        self.vs = [ {}, {} ]
        for i, nums in enumerate(self.nums):
            for j, v in enumerate(nums):
                self.vs[i][v] = j
        return max(self.dfs(0, 0), self.dfs(1, 0)) % MOD
        
    def dfs(self, idx, p):
        key = (idx, p)
        if key in self.d:
            return self.d[key]
        assert p <= len(self.nums[idx])
        if len(self.nums[idx]) == p:
            return 0
        res = 0
        res = max(res, self.dfs(idx, p + 1))
        v = self.nums[idx][p]
        if v in self.vs[idx ^ 1]:
            nxt = self.vs[idx ^ 1][v]
            res = max(res, self.dfs(idx ^ 1, nxt + 1))
        res += v
        self.d[key] = res
        # print key, res
        return res
        
        
