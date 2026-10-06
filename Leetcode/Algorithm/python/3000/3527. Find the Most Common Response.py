from collections import defaultdict

class Solution(object):
    def findCommonResponse(self, responses):
        d = defaultdict(int)
        for resp in responses:
            resp = set(resp)
            for item in resp:
                d[item] += 1
        f = sorted(d.items(), key=lambda (key, count): (-count, key))[0]
        return f[0]
