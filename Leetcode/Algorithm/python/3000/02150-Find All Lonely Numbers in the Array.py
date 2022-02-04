from collections import Counter
INF = 10 ** 10
class Solution(object):
    def findLonely(self, nums):
        nums.sort()
        n = len(nums)
        res = []
        for i in xrange(n):
            left = INF if i - 1 < 0 else nums[i - 1]
            right = INF if i + 1 >= n else nums[i + 1]
            if abs(left - nums[i]) > 1 and abs(right - nums[i]) > 1:
                res.append(nums[i])
        return res
        
'''
^^^^TEST^^^^
[10,6,5,8]
-------
[10, 8]
$$$TEST$$$

^^^^TEST^^^^
[1,3,5,3]
-------
[1, 5]
$$$TEST$$$
'''
