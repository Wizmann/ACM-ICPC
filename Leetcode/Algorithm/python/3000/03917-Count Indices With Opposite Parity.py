class Solution(object):
    def countOppositeParity(self, nums):
        odds, evens = 0, 0
        for num in nums:
            odds += num % 2
            evens += (num % 2) ^ 1
        res = []
        for num in nums:
            if num % 2 == 1:
                res.append(evens)
                odds -= 1
            else:
                res.append(odds)
                evens -= 1
        return res
