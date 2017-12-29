class Solution(object):
    def dominantIndex(self, nums):
        maxi = max(nums)
        remains = filter(lambda x: x < maxi, nums)
        return nums.index(maxi) if all([x * 2 <= maxi for x in remains]) else -1
