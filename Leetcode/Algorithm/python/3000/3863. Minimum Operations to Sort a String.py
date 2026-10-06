class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n <= 1:
            return 0

        # Fast sortedness check (single Python-level pass).
        prev = s[0]
        for i in xrange(1, n):
            ch = s[i]
            if ch < prev:
                break
            prev = ch
        else:
            return 0

        # Length 2 and not sorted is impossible.
        if n == 2:
            return -1

        # C-optimized string builtins are faster than Python-level counting.
        mn = min(s)
        mx = max(s)
        left = s[0]
        right = s[-1]

        if left == mn or right == mx:
            return 1

        if left == mx and right == mn and s.count(mn) == 1 and s.count(mx) == 1:
            return 3

        return 2
