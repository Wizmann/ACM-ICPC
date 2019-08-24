class Solution(object):
    def lastSubstring(self, s):
        n = len(s)
        p, q = 0, 1
        res = s
        while p < n and q < n:
            offset = 0
            while p + offset < n and q + offset < n and s[p + offset] == s[q + offset]:
                offset += 1
            if q + offset < n and s[p + offset] < s[q + offset]:
                p = q

            q = q + max(offset, 1)
            if p == q:
                q += 1
        return s[p:]

assert Solution().lastSubstring('babcbd') == 'd'
assert Solution().lastSubstring('abab') == 'bab'
assert Solution().lastSubstring('leetcode') == 'tcode'
