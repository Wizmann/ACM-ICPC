class Solution(object):
    def sumOddLengthSubarrays(self, arr):
        n = len(arr)
        for i in xrange(1, n):
            arr[i] += arr[i - 1]
        
        res = 0
        for i in xrange(1, n + 1, 2):
            for j in xrange(n):
                if j + i - 1 < n:
                    res += arr[j + i - 1] - (0 if j - 1 < 0 else arr[j - 1])
        return res
            
