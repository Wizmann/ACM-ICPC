class Solution(object):
    def rearrangeArray(self, nums):
        ps = filter(lambda x: x > 0, nums)
        ns = filter(lambda x: x < 0, nums)

        m = len(ps)
        res = []
        for i in xrange(m):
            res.append(ps[i])
            res.append(ns[i])
        return res

'''
^^^^TEST^^^^
[3,1,-2,-5,2,-4]
-------
[3,-2,1,-5,2,-4]
$$$TEST$$$
'''
