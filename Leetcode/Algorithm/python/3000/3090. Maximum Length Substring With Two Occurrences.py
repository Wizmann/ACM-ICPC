from collections import defaultdict

class Solution(object):
    def maximumLengthSubstring(self, s):
        l, r = 0, 0
        n = len(s)
        d = defaultdict(int)
        d['~'] = 0
        maxi = 0
        while l < n and r <= n:
            if max(d.values()) <= 2:
                maxi = max(maxi, r - l)
                if r >= n:
                    break
                d[s[r]] += 1
                r += 1
            else:
                d[s[l]] -= 1
                l += 1
        return maxi
            
