from collections import defaultdict

ALPHA = 29
MOD = (2 ** 61) - 1

fs = [1]
for i in xrange(123456):
    fs.append(fs[-1] * ALPHA % MOD)

class StringHash(object):
    def __init__(self, s):
        self.h = 0
        self.len = len(s)
        for c in s:
            c = ord(c) - ord('a') + 1
            self.h = (self.h * ALPHA + c) % MOD

    def appendLeft(self, s):
        assert isinstance(s, StringHash)
        self.h = (self.h + s.h * fs[self.len]) % MOD
        self.len += s.len
        return self

    def appendRight(self, s):
        assert isinstance(s, StringHash)
        self.h = self.h * fs[s.len] % MOD
        self.h = (self.h + s.h) % MOD
        self.len += s.len
        return self

class Solution(object):
    def findAnswer(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: List[bool]
        """
        self.g = defaultdict(list)
        for i, p in enumerate(parent):
            if p != -1:
                self.g[p].append(i)
        self.s = s
        self.n = len(parent)
        self.res = [-1 for i in xrange(self.n)]
        self.dfs(0)
        assert -1 not in self.res
        return self.res

    def dfs(self, cur):
        h1, h2 = StringHash(''), StringHash('')
        for nxt in self.g[cur]:
            (h1_, h2_) = self.dfs(nxt)

            h1.appendLeft(h1_)
            h2.appendRight(h2_)
        hcur = StringHash(self.s[cur])
        h1.appendLeft(hcur)
        h2.appendRight(hcur)

        self.res[cur] = (h1.h == h2.h)
        return h1, h2
