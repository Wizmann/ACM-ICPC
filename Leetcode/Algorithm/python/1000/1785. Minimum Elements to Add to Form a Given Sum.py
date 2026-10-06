class Solution(object):
    def minElements(self, nums, limit, goal):
        delta = abs(goal - sum(nums))
        return (delta + limit - 1) / limit
