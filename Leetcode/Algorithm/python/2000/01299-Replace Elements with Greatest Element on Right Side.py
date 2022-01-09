class Solution(object):
    def replaceElements(self, arr):
        maxi = -1
        n = len(arr)
        for i in xrange(n - 1, -1, -1):
            nxt = max(maxi, arr[i])
            arr[i] = maxi
            maxi = nxt
        return arr
