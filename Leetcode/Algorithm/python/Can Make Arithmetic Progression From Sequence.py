class Solution(object):
    def canMakeArithmeticProgression(self, arr):
        n = len(arr)
        arr.sort()
        delta = arr[1] - arr[0]
        for i in xrange(1, n):
            if arr[i] - arr[i - 1] != delta:
                return False
        return True
