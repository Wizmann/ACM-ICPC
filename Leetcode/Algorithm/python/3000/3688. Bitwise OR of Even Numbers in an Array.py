class Solution(object):
    def evenNumberBitwiseORs(self, nums):
        return reduce(lambda x, y: x | y, filter(lambda num: num % 2 == 0, nums), 0)
