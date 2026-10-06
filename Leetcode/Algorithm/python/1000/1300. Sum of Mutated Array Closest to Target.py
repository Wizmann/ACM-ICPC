INF = 10 ** 10

class Solution(object):
    def findBestValue(self, arr, target):
        arr.sort()
        left = 0
        n = len(arr)
        res = INF
        mini = INF
        pre = -INF
        for i in xrange(n):
            m = n - i
            for extra in [0, n - 1]:
                r = (target - left + extra) / m
                if r < pre: 
                    r = pre
                if r > arr[i]:
                    r = arr[i]
                right = r * m
                delta = abs(target - left - right)
                #print delta, mini, r, m
                if delta < mini:
                    mini = delta
                    res = r
                elif delta == mini:
                    res = min(res, r)
            left += arr[i]
            pre = arr[i]
        return res
