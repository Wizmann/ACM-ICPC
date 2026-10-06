from collections import defaultdict, Counter

class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        c = Counter(arr)
        ns = sorted(c.values())
        while ns and k >= ns[0]:
            k -= ns[0]
            ns.pop(0)
        return len(ns)
