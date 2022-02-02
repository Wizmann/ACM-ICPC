INF = 10 ** 10

class Solution(object):
    def maxScoreIndices(self, nums):
        maxi = -INF
        maxis = []

        left = 0
        right = sum(nums)

        n = len(nums)

        for i in xrange(n + 1):
            a = i - left
            b = right
            if a + b > maxi:
                maxi = a + b
                maxis = [i]
            elif a + b == maxi:
                maxis.append(i)
            if i < n:
                left += nums[i]
                right -= nums[i]
        return maxis

'''
^^^TEST^^^
[0,0,1,0]
-----
[2, 4]
$$$TEST$$$


^^^TEST^^^
[0,0,0]
-----
[3]
$$$TEST$$$


^^^TEST^^^
[1, 1]
-----
[0]
$$$TEST$$$
'''


