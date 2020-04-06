# https://leetcode.com/problems/construct-k-palindrome-strings/

from collections import defaultdict

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        d = defaultdict(int)
        for c in s:
            d[c] += 1
        print(d)
        for c, cnt in d.items():
            if cnt % 2 == 1:
                k -= 1
                d[c] -= 1
        print(k)
        if k < 0:
            return False
        p = 0
        for c, cnt in d.items():
            if k == 0:
                break
            assert cnt % 2 == 0
            while cnt and k > 0:
                k -= 1
                cnt -= 2
                p += 1
        return p >= k
