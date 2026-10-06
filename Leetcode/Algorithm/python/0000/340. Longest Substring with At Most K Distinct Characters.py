from collections import defaultdict

class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        if k == 0:
            return 0
        d = defaultdict(int)
        n = len(s)
        p, q = 0, 0
        ans = 0
        while p < n and q < n:
            while q < n and len(d) <= k:
                d[s[q]] += 1
                q += 1
                if len(d) <= k:
                    ans = max(ans, q - p)
            
            while p < q and len(d) > k:
                d[s[p]] -= 1
                if d[s[p]] == 0:
                    del d[s[p]]
                p += 1
        return ans
                
