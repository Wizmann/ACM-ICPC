class Solution(object):
    def findContestMatch(self, n):
        res = str(self.solve(range(1, n + 1)))
        return res.replace(' ', '')
        
    def solve(self, items):
        items = sorted(items)
        n = len(items)
        if n == 1:
            return items[0]
        res = []
        for i in xrange(n / 2):
            res.append((items[i], items[n - i - 1]))
        return self.solve(res)
