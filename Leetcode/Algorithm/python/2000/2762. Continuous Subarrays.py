from collections import defaultdict
class Solution(object):
    def continuousSubarrays(self, nums):
        n = len(nums)
        p, q = 0, 0
        d = defaultdict(int)
        res = 0

        while p < n and q < n:
            cur = nums[q]
            if p < q:
                mini, maxi = min(d.keys()), max(d.keys())
                while p < q and (abs(cur - mini) > 2 or abs(cur - maxi) > 2):
                    pre = nums[p]
                    d[pre] -= 1
                    if d[pre] == 0:
                        del d[pre]
                    mini, maxi = min(d.keys()), max(d.keys())
                    p += 1
            d[cur] += 1
            q += 1
            res += q - p
            print q - p
        return res

'''
^^^^TEST^^^^
[5,4,2,4]
----------------
8
$$$$TEST$$$$

^^^^TEST^^^^
[1, 2, 3]
----------------
6
$$$$TEST$$$$

'''


