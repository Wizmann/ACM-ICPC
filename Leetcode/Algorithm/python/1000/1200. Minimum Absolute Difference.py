INF = 10 ** 10

class Solution(object):
    def minimumAbsDifference(self, arr):
        arr.sort()
        res = []
        n = len(arr)
        mind = INF
        for i in xrange(n - 1):
            a, b = arr[i], arr[i + 1]
            if b - a < mind:
                res = []
                mind = b - a
                
            if b - a == mind:
                res.append([a, b])
        return res
