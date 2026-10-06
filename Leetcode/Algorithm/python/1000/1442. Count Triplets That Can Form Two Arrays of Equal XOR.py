from collections import defaultdict

class Solution(object):
    def countTriplets(self, arr):
        d = defaultdict(list)
        d[0].append(-1)
        pre = 0
        res = 0
        for i, num in enumerate(arr):
            pre ^= num
            d[pre].append(i)
        print d
        for nums in d.values():
            m = len(nums)
            for i in xrange(m):
                for j in xrange(i + 1, m):
                    a = nums[i]
                    b = nums[j]
                    # print a, b
                    res += b - a - 1
        return res
