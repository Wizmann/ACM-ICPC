class Solution(object):
    def findNumbers(self, nums):
        return len(filter(lambda s: len(str(s)) % 2 == 0, nums))
