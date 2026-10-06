class Solution(object):
    def checkGoodInteger(self, n):
        nums = map(int, str(n))
        ds = sum(nums)
        ss = sum(map(lambda x: x * x, nums))
        return ss - ds >= 50
