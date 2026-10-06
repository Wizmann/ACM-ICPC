class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        assert len(s) == len(t)
        n = len(s)
        
        p, q = 0, 0
        tot = 0
        res = 0
        while p < n and q < n:
            tot += abs(ord(s[q]) - ord(t[q]))
            while tot > maxCost:
                tot -= abs(ord(s[p]) - ord(t[p]))
                p += 1
            res = max(res, q - p + 1)
            q += 1
        return res
        
