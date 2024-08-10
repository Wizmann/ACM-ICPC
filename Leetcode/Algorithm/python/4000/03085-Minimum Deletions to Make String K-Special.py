from collections import Counter
INF = 10 ** 10
class Solution(object):
    def minimumDeletions(self, word, k):
        c = Counter(word)
        ns = sorted(c.values())
        n = len(ns)
        l, r = 0, 0
        mini = INF
        # print ns
        while l < n and r < n:
            while r < n and ns[r] - ns[l] <= k:
                r += 1
            # print l, r
            tot = sum(ns[:l]) + sum(ns[r:]) - (n - r) * (ns[l] + k)
            mini = min(mini, tot)
            l += 1
        return mini
