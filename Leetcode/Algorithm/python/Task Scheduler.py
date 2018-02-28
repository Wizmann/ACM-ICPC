from collections import Counter

class Solution(object):
    def leastInterval(self, tasks, m):
        n = len(tasks)
        c = sorted(Counter(tasks).values(), reverse=True)

        maxi = c[0]
        mcount = c.count(maxi)

        return max(len(tasks), (m + 1) * (maxi - 1) + mcount)
