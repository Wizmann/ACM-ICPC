from collections import defaultdict

MOD = (10 ** 9) + 7

class Solution(object):
    def numOfWays(self, n):
        pattern = []
        for i in xrange(3):
            for j in xrange(3):
                for k in xrange(3):
                    if i == j or j == k:
                        continue
                    pattern.append((i, j, k))
                    
        d = [defaultdict(int), defaultdict(int)]
        for p in pattern:
            d[0][p] = 1
            
        p = 0
        for i in xrange(1, n):
            q = p ^ 1
            d[q] = defaultdict(int)
            for p1 in pattern:
                for p2 in pattern:
                    flag = True
                    for j in xrange(3):
                        if p1[j] == p2[j]:
                            flag = False
                            break
                    if not flag:
                        continue
                    d[q][p2] = (d[q][p2] + d[p][p1]) % MOD
            p = q
        return sum(d[p].values()) % MOD
