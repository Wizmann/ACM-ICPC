class Solution(object):
    def minLengthAfterRemovals(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        for c in s:
            if c == 'a':
                cnt += 1
            else:
                cnt -= 1
        return abs(cnt)
