class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        n = len(nums)
        tot = reduce(lambda x, y: x ^ y, nums)
        res = []
        for i in xrange(n):
            res.append( ((1 << maximumBit) - 1) ^ tot )
            tot ^= nums.pop()
        return res

'''
^^^TEST^^^
[0,1,1,3]
2
-------
[0,3,2,3]
$$$TEST$$$


^^^TEST^^^
[2,3,4,7]
3
-------
[5,2,6,5]
$$$TEST$$$

^^^TEST^^^
[0,1,2,2,5,7]
3
-------
[4,3,6,4,6,7]
$$$TEST$$$
'''
