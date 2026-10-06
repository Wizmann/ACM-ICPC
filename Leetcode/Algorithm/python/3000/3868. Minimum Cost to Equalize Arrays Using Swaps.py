from collections import Counter

class Solution(object):
    def minCost(self, nums1, nums2):
        c1 = Counter(nums1)
        c2 = Counter(nums2)
        items = set(nums1 + nums2)
        cnt = 0
        for num in items:
            delta = c1.get(num, 0) - c2.get(num, 0)
            if delta % 2 == 0:
                cnt += abs(delta) / 2
            else:
                cnt = -1
                break
        return cnt / 2
