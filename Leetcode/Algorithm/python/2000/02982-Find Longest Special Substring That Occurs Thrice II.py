import string
from collections import defaultdict

class Solution(object):
    def maximumLength(self, s):
        n = len(s)
        d = defaultdict(list)
        pre = None
        cnt = 0
        for c in s + '$':
            if c == pre:
                cnt += 1
            else:
                if pre:
                    d[pre].append(cnt)
                pre = c
                cnt = 1
        maxi = -1
        for c in string.lowercase:
            if not d[c]:
                continue
            l, r = 0, n
            while l <= r:
                m = (l + r) / 2
                res = 0
                for cnt in d[c]:
                    if cnt >= m:
                        res += cnt - m + 1
                    if res >= 3:
                        break
                if res >= 3:
                    l = m + 1
                else:
                    r = m - 1
            maxi = max(maxi, r)
        if maxi == 0:
            maxi = -1
        return maxi
