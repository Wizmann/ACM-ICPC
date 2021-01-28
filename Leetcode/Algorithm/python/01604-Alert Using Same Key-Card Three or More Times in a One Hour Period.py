from collections import defaultdict

def timeToMinutes(hhmm):
    h, m = map(int, hhmm.split(':'))
    return h * 60 + m

class Solution(object):
    def alertNames(self, keyName, keyTime):
        d = defaultdict(list)
        for k, t in zip(keyName, keyTime):
            d[k].append(timeToMinutes(t))
        res = []
        for k, ts in d.items():
            if len(ts) < 3:
                continue
            ts.sort()
            m = len(ts)
            for i in xrange(m - 2):
                l = ts[i]
                r = ts[i + 2]
                if r - l <= 60:
                    res.append(k)
                    break
        return sorted(res)
