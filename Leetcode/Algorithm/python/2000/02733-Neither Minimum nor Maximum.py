class Solution(object):
    def findNonMinOrMax(self, nums):
        mini = min(nums)
        maxi = max(nums)

        res = filter(lambda x: x not in [mini, maxi], nums)
        return res[0] if res else -1
