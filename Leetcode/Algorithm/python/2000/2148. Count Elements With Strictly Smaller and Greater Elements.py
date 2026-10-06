class Solution(object):
    def countElements(self, nums):
        cnt = 0
        n = len(nums)
        mini = min(nums)
        maxi = max(nums)
        for i in xrange(n):
            cur = nums[i]
            if mini < cur < maxi:
                cnt += 1
        return cnt

'''
^^^TEST^^^^
[11,7,2,15]
-------
2
$$$$$TEST$$$$


^^^TEST^^^^
[-3,3,3,90]
-------
2
$$$$$TEST$$$$

'''
