class Solution(object):
    def intersection(self, nums):
        return sorted(reduce(lambda x, y: x & y, map(set, nums)))
