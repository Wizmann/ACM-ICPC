from collections import defaultdict 

def factor(x):
    res = 1
    for i in xrange(1, x + 1):
        res *= i
    return res

class Solution(object):
    def getProbability(self, balls):
        cnt = sum(balls)
        self.cnt = cnt
        tot = 1
        for i in xrange(1, cnt + 1):
            tot *= i
        for b in balls:
            tot /= factor(b)

        self.d = {}
        res = self.dfs(0, cnt / 2, 0, balls, lambda rem, delta: rem == 0 and delta == 0)
        return 1.0 * res / tot
        
    def dfs(self, cur, rem, delta, balls, func):
        key = (cur, rem, delta)
        if key in self.d:
            return self.d[key]
        if cur == len(balls):
            self.d[key] = factor(self.cnt / 2) ** 2 if func(rem, delta) else 0
            return self.d[key]
        b = balls[cur]
        res = 0
        for i in xrange(min(b, rem) + 1):
            l, r = i, b - i
            if l == 0 and r != 0:
                res += self.dfs(cur + 1, rem - i, delta - 1, balls, func) / factor(l) / factor(r)
            elif l != 0 and r != 0:
                res += self.dfs(cur + 1, rem - i, delta, balls, func) / factor(l) / factor(r)
            elif l != 0 and r == 0:
                res += self.dfs(cur + 1, rem - i, delta + 1, balls, func) / factor(l) / factor(r)
            else:
                assert False
        self.d[key] = res
        return res
        
