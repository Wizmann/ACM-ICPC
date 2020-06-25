class Solution(object):
    def canBeEqual(self, target, arr):
        return sorted(target) == sorted(arr)
