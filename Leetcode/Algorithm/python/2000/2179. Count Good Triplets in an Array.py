from collections import defaultdict

class BITree(object):
    def __init__(self, n):
        self.n = n + 1
        self.nums = [0 for i in xrange(self.n + 1)]
        
    def lowbit(self, x):
        return x & (-x)
    
    def add(self, pos, value):
        while pos < self.n:
            self.nums[pos] += value
            pos += self.lowbit(pos)
    
    def query(self, pos):
        res = 0
        while pos:
            res += self.nums[pos]
            pos -= self.lowbit(pos)
        return res
    
    def query_range(self, a, b):
        return self.query(b) - self.query(a - 1)

class Solution(object):
    def goodTriplets(self, nums1, nums2):
        d2 = {}
        for i, num in enumerate(nums2):
            d2[num] = i

        n = len(nums1)

        bit1 = BITree(n)
        bit2 = BITree(n)

        dp1 = defaultdict(int)
        dp2 = defaultdict(int)

        for i in xrange(n):
            cur = nums1[i]
            nxt = d2[cur]
            dp1[cur] = bit1.query_range(1, nxt + 1)

            bit1.add(nxt + 1, 1)

        for i in xrange(n - 1, -1, -1):
            cur = nums1[i]
            nxt = d2[cur]
            dp2[cur] = bit2.query_range(nxt + 1, n)

            bit2.add(nxt + 1, 1)

        res = 0
        for i in xrange(n):
            res += dp1[i] * dp2[i]
        return res

'''
^^^TEST^^^
[2,0,1,3]
[0,1,2,3]
-------
1
$$$TEST$$$

^^^TEST^^^
[4,0,1,3,2]
[4,1,0,2,3]
-------
4
$$$TEST$$$

'''
