from collections import Counter

class Solution(object):
    def uniqueOccurrences(self, arr):
        c = Counter(Counter(arr).values())
        return len(c) == sum(c.values())
