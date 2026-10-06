# https://leetcode.com/problems/increasing-decreasing-string/

import string
from collections import Counter

class Solution:
    def sortString(self, s: str) -> str:
        n = len(s)
        cnt = Counter(s)
        res = ''
        m = 0
        alphabet = string.ascii_lowercase + string.ascii_lowercase[::-1]
        while True:
            for c in alphabet:
                if cnt[c] > 0:
                    res += c
                    m += 1
                    cnt[c] -= 1
            if m == n:
                break
        return res
                
