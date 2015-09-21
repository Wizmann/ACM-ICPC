class Solution(object):
    def __init__(self):
        self.res = set([])
    
    def addOperators(self, nums, target):
        n = len(nums)
        for i in xrange(1, n + 1):
            left, right = nums[:i], nums[i:]
            if not self.leading_zero(left):
                self.dfs(right, 0, int(left), target, left)
        return list(self.res)
    
    def dfs(self, nums, total, pre, target, expr):
        if not nums:
            if total + pre == target:
                self.res.add(expr)
            return
        n = len(nums)
        for i in xrange(1, n + 1):
            left, right = nums[:i], nums[i:]
            if self.leading_zero(left):
                continue
            left_i = int(left)
            
            self.dfs(right, total + pre, left_i,       target, expr + '+' + left)
            self.dfs(right, total + pre, -left_i,      target, expr + '-' + left)
            self.dfs(right, total,       pre * left_i, target, expr + '*' + left)

    def leading_zero(self, nums):
        return len(nums) > 1 and nums[0] == '0'
