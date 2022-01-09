INF = 10 ** 10

class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        arr.sort()
        n = len(arr)
        
        res = len(arr)
        pre = INF
        for i in xrange(n - 1, -1, -1):
            cur = min(arr[i], n + 1)
            r = cur + (n - i - 1)
            res = min(res, r)
        return res
