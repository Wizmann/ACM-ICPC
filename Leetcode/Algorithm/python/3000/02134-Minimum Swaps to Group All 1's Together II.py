class Solution(object):
    def minSwaps(self, nums):
        n = len(nums)
        m = sum(nums)
        l, r = 0, m - 1
        cur = sum(nums[:m])

        res = m - cur

        for i in xrange(n):
            cur += nums[(i + m) % n]
            cur -= nums[i]
            # print i, (i + m) % n, cur
            res = min(res, m - cur)
        return res

'''
^^^TEST^^^
[0,1,0,1,1,0,0]
------
1
$$$TEST$$$


^^^^^TEST^^^^
[0,1,1,1,0,0,1,1,0]
------
2
$$$TEST$$$$

^^^^TEST^^^
[1,1,0,0,1]
-------
0
$$$TEST$$$
'''


        
