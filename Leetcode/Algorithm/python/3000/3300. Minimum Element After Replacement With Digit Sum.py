class Solution(object):
    def minElement(self, nums):
        return min(map(lambda x: sum(map(int, str(x))), nums))
