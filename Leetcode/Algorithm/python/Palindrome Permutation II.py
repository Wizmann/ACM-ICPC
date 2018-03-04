from collections import Counter

class Solution(object):
    def generatePalindromes(self, s):
        n = len(s)
        c = Counter(s)
        odd = len(filter(lambda x: x % 2 != 0, c.values()))
        if odd != n % 2:
            return []
        self.res = []
        self.buffer = ['' for i in xrange(n)]
        self.dfs(n, c, 0, n - 1)
        return self.res
    
    def dfs(self, n, c, p, q):
        if p > q:
            self.res.append(''.join(self.buffer))
            return
        elif p == q:
            for (key, value) in c.items():
                if not value:
                    continue
                self.buffer[p] = key
                self.dfs(n, c, p + 1, q - 1)
        else:
            for (key, value) in c.items():
                if value < 2:
                    continue
                self.buffer[p] = self.buffer[q] = key
                c[key] -= 2
                self.dfs(n, c, p + 1, q - 1)
                c[key] += 2
