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
        a = max(0, a - 1)
        return self.query(b) - self.query(a)

class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        n = len(nums1)
        nums = []
        for i in xrange(n):
            delta1 = nums1[i] - nums2[i] - diff
            delta2 = nums1[i] - nums2[i]
            nums.append(delta1)
            nums.append(delta2)
        d = {}
        nums = sorted(set(nums))
        for i, num in enumerate(nums):
            d[num] = i + 1
        
        bit = BITree(len(d) + 1)
        m = len(d) + 1
        for i in xrange(n):
            pos = d[nums1[i] - nums2[i]]
            bit.add(pos, 1)
        res = 0
        for i in xrange(n):
            pos = d[nums1[i] - nums2[i]]
            bit.add(pos, -1)
            pos = d[nums1[i] - nums2[i] - diff]
            res += bit.query_range(pos, m)
        return res
        
