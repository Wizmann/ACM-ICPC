from collections import Counter

class Solution(object):
    def areOccurrencesEqual(self, s):
        c = Counter(s)
        return len(set(c.values())) == 1
