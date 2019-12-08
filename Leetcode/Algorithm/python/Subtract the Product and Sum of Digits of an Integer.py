class Solution(object):
    def subtractProductAndSum(self, n):
        nums = map(int, str(n))
        p = reduce(lambda x, y: x * y, nums, 1)
        s = sum(nums)
        return p - s
