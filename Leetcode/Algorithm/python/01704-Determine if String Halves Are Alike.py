from collections import Counter

class Solution(object):
    def halvesAreAlike(self, s):
        VOWELS = ['a', 'e', 'i', 'o', 'u']
        n = len(s)
        left = Counter(s.lower()[:n/2])
        right = Counter(s.lower()[n/2:])
        v1, v2 = 0, 0
        for v in VOWELS:
            v1 += left.get(v, 0)
            v2 += right.get(v, 0)
        return v1 == v2
