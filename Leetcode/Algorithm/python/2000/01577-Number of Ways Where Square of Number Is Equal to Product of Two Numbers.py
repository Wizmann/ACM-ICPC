from collections import defaultdict

class Solution(object):
    def numTriplets(self, nums1, nums2):
        return self.solve(nums1, nums2) + self.solve(nums2, nums1)
    
    def solve(self, nums1, nums2):
        d1 = defaultdict(int)
        for num in nums1:
            d1[num] += 1
        d2 = defaultdict(int)
        for num in nums2:
            d2[num] += 1
        res = 0
        for (k1, v1) in d1.items():
            for (k2, v2) in sorted(d2.items()):
                if (k1 * k1) % k2 != 0:
                    continue
                u = (k1 * k1) / k2
                if u == k2:
                    res += v1 * v2 * (v2 - 1) / 2
                elif u > k2:
                    res += v1 * v2 * d2[u]
        return res
            
