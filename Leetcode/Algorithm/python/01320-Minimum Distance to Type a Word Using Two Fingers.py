N = 26 * 26
INF = 10 ** 10

class Solution(object):
    def minimumDistance(self, word):
        dp = [ [0 for i in xrange(N)] for j in xrange(2) ]
        word = map(lambda c: ord(c) - ord('A'), word)
        
        p = 0
        for w in word:
            q = p ^ 1
            dp[q] = [INF for i in xrange(N)]
            for i in xrange(N):
                l = i / 26
                r = i % 26
                step = dp[p][i]
                
                if step >= INF:
                    continue
                
                dl = self.getDistance(l, w)
                dr = self.getDistance(r, w)
                
                dp[q][self.getId(w, r)] = min(dp[q][self.getId(w, r)], step + dl)
                dp[q][self.getId(l, w)] = min(dp[q][self.getId(l, w)], step + dr)
            p = q
        return min(dp[p])
                
    def getId(self, l, r):
        return l * 26 + r
    
    def getDistance(self, a, b):
        ya, xa = a / 6, a % 6
        yb, xb = b / 6, b % 6
        return abs(ya - yb) + abs(xa - xb)
