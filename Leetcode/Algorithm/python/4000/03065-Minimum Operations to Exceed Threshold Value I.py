class Solution(object):
    def minOperations(self, nums, k):
        return len(filter(lambda x: x < k, nums))
