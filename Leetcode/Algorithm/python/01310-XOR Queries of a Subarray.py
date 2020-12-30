class Solution(object):
    def xorQueries(self, arr, queries):
        n = len(arr)
        for i in xrange(1, n):
            arr[i] ^= arr[i - 1]
            
        res = []
        for (a, b) in queries:
            l = 0 if a - 1 < 0 else arr[a - 1]
            r = arr[b]
            
            res.append(l ^ r)
        return res
