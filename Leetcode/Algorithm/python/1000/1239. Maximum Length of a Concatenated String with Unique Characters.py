class Solution(object):
    def maxLength(self, arr):
        n = len(arr)
        ans = 0
        for i in xrange(1 << n):
            s = ''
            for j in xrange(n):
                if i & (1 << j):
                    s += arr[j]
            #print s
            if len(s) == len(set(s)):
                ans = max(ans, len(s))
        return ans
