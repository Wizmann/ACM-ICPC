from collections import defaultdict

MOD = (10 ** 9) + 7

class Solution(object):
    def countRoutes(self, locations, start, finish, fuel):
        n = len(locations)
        d = [ defaultdict(int) for i in xrange(fuel + 1) ]
        d[fuel][start] = 1
        for f in xrange(fuel, -1, -1):
            for p, cnt in d[f].items():
                for i in xrange(n):
                    if i == p:
                        continue
                    dis = abs(locations[p] - locations[i])
                    if dis > f:
                        continue
                    d[f - dis][i] += cnt
                    d[f - dis][i] %= MOD
        res = 0
        for f in xrange(fuel + 1):
            res += d[f][finish]
            res %= MOD
        return res
