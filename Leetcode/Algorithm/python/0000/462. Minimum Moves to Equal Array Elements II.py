from random import randint

class Solution(object):
    def minMoves2(self, nums):
        l, r = min(nums), max(nums)
        n = len(nums)
        while l <= r:
            mid = randint(l, r)
            cnt = sum(num < mid for num in nums)
            
            if cnt == n / 2:
                r = mid
                break

            if cnt <= n / 2:
                l = mid + 1
            else:
                r = mid - 1
        return sum(abs(num - r) for num in nums)

'''
^^^TEST^^^
[1, 1, 1]
-------
0
$$$TEST$$$

^^^TEST^^^
[1, 2, 3]
-------
2
$$$TEST$$$

^^^TEST^^^
[1,10,2,9]
-------
16
$$$TEST$$$

'''
