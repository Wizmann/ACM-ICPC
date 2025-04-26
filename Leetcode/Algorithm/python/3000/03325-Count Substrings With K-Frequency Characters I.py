from collections import defaultdict

class Solution(object):
    def numberOfSubstrings(self, s, k):
        n = len(s)
        d = defaultdict(int)
        
        cnt = 0
        pre = 0
        for i, c in enumerate(s):
            d[c] += 1
            if d[c] >= k:
                r = n - i
                l = 0
                while d[c] >= k:
                    l += 1
                    d[s[pre]] -= 1
                    pre += 1
                cnt += l * r                
        return cnt
