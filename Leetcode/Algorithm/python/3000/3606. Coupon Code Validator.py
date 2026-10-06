import re

busList = ["electronics", "grocery", "pharmacy", "restaurant"]

class Solution(object):
    def validateCoupons(self, code, businessLine, isActive):
        n = len(code)
        res = []
        for i in xrange(n):
            c, b, a = code[i], businessLine[i], isActive[i]
            if not re.match(r'^\w+$', c):
                continue
            if b not in busList:
                continue
            if not a:
                continue
            res.append((busList.index(b), c))
        res.sort()
        return map(lambda x: x[1], res)
