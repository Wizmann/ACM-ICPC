class Solution(object):
    def absDifference(self, nums, k):
        nums.sort()
        maxi = sum(nums[-k:])
        mini = sum(nums[:k])
        return maxi - mini
