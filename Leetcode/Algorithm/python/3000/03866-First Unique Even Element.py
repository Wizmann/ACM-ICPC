from collections import Counter

class Solution(object):
    def firstUniqueEven(self, nums):
        c = Counter(nums)
        for num in nums:
            if num % 2 == 0 and c[num] == 1:
                return num
        return -1
